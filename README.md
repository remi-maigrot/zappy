# Zappy

A networked multiplayer simulation with a C game server, an SFML graphical client and Python AI players, all talking over a custom TCP protocol.

## About

Built in 2023. Zappy takes place on Trantor, a world where resources (food and six kinds of stones) spawn randomly on a tile map. Teams of autonomous AI players ("Trantorians") must gather resources, survive by eating, and perform elevation rituals to level up. The first team with six players at the maximum level wins.

The project is split into three independent programs:

- **Server** (C): owns the world state, the game clock and the network protocol.
- **GUI** (C++ / SFML): a spectator client that renders the map, resources and players.
- **AI** (Python): autonomous clients, each driving one Trantorian.

## Features

**Server**
- Single-threaded TCP server multiplexing all clients with `select()`.
- Time-based game loop driven by a configurable frequency (`-f`): resources are refilled and food is consumed on each tick.
- World generation with a resource density per type, team management and per-team client slots.
- Graphical protocol: `msz`, `bct`, `mct`, `tna`, `ppo`, `plv`, `pin`, `sgt`, `sst`, plus `pnw` new-player notifications.
- Hand-written generic linked-list library and utility library in C.
- Unit tests with Criterion.

**GUI**
- SFML window displaying the tile map, resources and players.
- Command dispatcher mapping server messages to handlers (map size, tile content, team names, player position / level / inventory, time unit).

**AI**
- TCP client that joins a team and reads the world size and remaining slots.
- State machine (food search, stone search, elevation) driven by `Look` / `Inventory` results.
- Path finding toward resources visible in the player's vision cone.
- Team coordination through `Broadcast` messages.
- Unit tests with `unittest`.

## Tech stack

- **Server**: C, `gcc`, POSIX sockets, `select()`, Criterion
- **GUI**: C++17, SFML
- **AI**: Python 3.10+, `socket`, `unittest`
- GNU Make

## Architecture

```
          ┌──────────────────────┐
          │   Server (C)         │  world state, tick loop,
          │   select() over TCP  │  resource spawn, protocol
          └───────┬───────┬──────┘
          AI cmds │       │ GUI protocol (msz, bct, ppo, ...)
                  │       │
   ┌──────────────▼─┐   ┌─▼────────────────┐
   │ AI (Python)    │   │ GUI (C++/SFML)   │
   │ one process    │   │ spectator view   │
   │ per player     │   │                  │
   └────────────────┘   └──────────────────┘

Server/
├── src/                  main loop, client handling, map & resources, teams
│   ├── commands_gui/     graphical protocol handlers
│   └── commands_ai/      player command handlers (work in progress at submission)
├── lib/linked_lists/     generic linked list
├── lib/my/               string / printf utilities
└── tests/                Criterion tests
GUI/
├── src/Core/             Core + server command handlers
├── src/Server/           Socket, ServerProtocol
└── src/Views/            SFML rendering (Tile, Player)
ai/
├── main.py               entry point
└── src/                  Trantorian state machine, parser, server client, requests
```

## Build & Run

Requirements: `gcc`, `g++` (C++17), SFML 2.5, Python 3.10+, `make`. Criterion is needed for the C tests.

```bash
# Debian / Ubuntu
sudo apt install build-essential libsfml-dev python3 libcriterion-dev
```

```bash
make            # builds ./zappy_server, ./zappy_gui and ./zappy_ai
make server     # server only
make tests_run  # Server and GUI unit tests
make fclean
```

Start the server, then connect a GUI and AI players:

```bash
./zappy_server -p 4242 -x 10 -y 10 -n team1 team2 -c 6 -f 100
./zappy_gui -p 4242 -h localhost
./zappy_ai -p 4242 -n team1 -h localhost
```

```
zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
zappy_gui    -p port -h machine
zappy_ai     -p port -n name [-h machine]
```

Run the AI tests:

```bash
python3 -m unittest discover ai/tests
```
