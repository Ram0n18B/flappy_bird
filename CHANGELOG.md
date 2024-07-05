# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.0.1] - 2024-06-05

### Added

- Se agregaron dos archivos al directorio states: PauseState.cpp y PauseState.hpp para darle al juego la funcionalidad de pausar la partida.

### Changed

- Se modifico Bird ahora va a contener el score del juego agregando: una variable para el score y tres nuevos metodos para modificar y obtener addScore(), getScore() y scoreReset().
- Ahora bird va a ser instanciado desde el estado TitleScreenState.
- Se modifico el metodo handle_inputs de PlayingState para agregar la funcionalidad de que con la tecla p pausar el juego.
