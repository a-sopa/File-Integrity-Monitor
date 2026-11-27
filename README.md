# File-Integrity-Monitor

A lightweight C++ File Integrity Monitor (FIM) that creates a SHA-256 baseline of files in a target directory and continuously monitors them for unauthorized modifications.

## Features

- **Recursive Directory Scanning**: Scans all regular files in the target directory using `std::filesystem::recursive_directory_iterator` (skipping permission-denied entries).
- **Symlink-Safe File Reading**: Reads files using POSIX `open()` with `O_RDONLY | O_NOFOLLOW` to avoid following symbolic links.
- **SHA-256 Hashing**: Computes cryptographic SHA-256 digests using OpenSSL's `EVP` API.
- **Continuous Monitoring**: Compares current file hashes against the initial baseline every 2 seconds.
- **Color-Coded Terminal Alerts**:
  - `[ALERT: FILE INTEGRITY COMPROMISED]` — Reported when a file's hash differs from its baseline.
  - `[FILE REQUIRES ATTENTION]` — Reported for files previously flagged as compromised.
  - `[FILES ARE SAFE]` — Reported when no integrity violations are detected in the current scan.

## Project Structure

- `main.cpp` — Entry point, baseline creation, and monitoring loop.
- `FIM.hpp` / `FIM.cpp` — Directory scanning, file reading, SHA-256 calculation, and baseline snapshot logic.
- `auxiliar.hpp` / `auxiliar.cpp` — Terminal output formatting, alert helpers, and screen clearing.
- `Makefile` — Build configuration (`g++`, C++17, `-lcrypto`).
- `config.txt` — Configuration file (reserved for future use).
- `tests/` — Default directory monitored by the application (`DIRECTORY_TO_READ` in `FIM.hpp`).

## Requirements

- Linux / WSL (POSIX `fcntl.h`, `unistd.h`)
- `g++` with C++17 support
- OpenSSL development library (`libssl-dev` / `-lcrypto`)

## Build & Run

```bash
make
./main
```

To clean build artifacts:

```bash
make clean
```

## Future Features

- **New & Deleted File Detection**: Track files added to or removed from the monitored directory after the initial snapshot.
- **Persistent Baselines**: Save and load baseline snapshots to/from disk so integrity checks persist across restarts.
- **Menu**: Create a Menu so the user can check the differences between the files, unflag the files, and much more...
- **Timestamped Logging**: Write alerts and scan events to a dedicated log file in addition to terminal output.
- **File Open Alert**: Alert the user when a sensitive file is opened
