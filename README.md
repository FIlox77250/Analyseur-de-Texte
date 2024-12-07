# 📝 Analyseur de Texte

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen.svg)](https://www.microsoft.com/windows)
[![Build](https://img.shields.io/badge/Build-CMake-orange.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

> Un analyseur de texte moderne avec interface graphique Windows, développé en C++.

<div align="center">
  <img src="/api/placeholder/800/400" alt="Aperçu de l'application">
</div>

## ✨ Caractéristiques

- 📊 Analyse complète du texte
  - Comptage de caractères (total et sans espaces)
  - Comptage de mots
  - Comptage de phrases
- 🎨 Interface graphique intuitive
- ⚡ Analyse instantanée
- 🔍 Support Unicode complet
- 💫 Performances optimisées

## 🚀 Pour Commencer

### Prérequis

- 💻 Windows 10/11
- 🛠️ MinGW-w64 (GCC pour Windows)
- 📦 CMake 3.10+
- 🎯 CLion (recommandé) ou tout autre IDE C++

### Installation

1. **Clonez le dépôt**
   ```bash
   git clone https://github.com/votre-nom/analyseur-texte.git
   cd analyseur-texte
   ```

2. **Configuration avec CMake**
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. **Compilation**
   ```bash
   cmake --build .
   ```

## 💡 Utilisation

1. **Lancez l'application**
   - Double-cliquez sur `Analyseur_de_Texte.exe`
   - Ou lancez depuis votre IDE

2. **Analysez votre texte**
   - Entrez ou collez votre texte
   - Cliquez sur "Analyser"
   - Consultez les résultats instantanément

## 📁 Structure du Projet

```
analyseur-texte/
├── 📄 CMakeLists.txt     # Configuration CMake
├── 📄 main.cpp           # Code source principal
├── 📄 README.md          # Documentation
└── 📁 build/             # Dossier de compilation
```

## ⚙️ Configuration CMake

```cmake
cmake_minimum_required(VERSION 3.10)
project(Analyseur_de_Texte)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_libraries(${PROJECT_NAME} 
    comctl32
    gdi32
    user32
    kernel32
)
```

## 🔧 Compilation Manuelle

Pour les utilisateurs préférant la ligne de commande :

```bash
g++ -o analyseur.exe main.cpp -mwindows -lgdi32 -luser32 -lkernel32
```

## 🤝 Contribution

Les contributions sont bienvenues ! Voici comment participer :

1. 🍴 Fork le projet
2. 🔨 Créez votre branche de fonctionnalité
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. 💾 Commitez vos changements
   ```bash
   git commit -m 'Add: Amazing Feature'
   ```
4. 📤 Poussez vers la branche
   ```bash
   git push origin feature/AmazingFeature
   ```
5. 🔄 Ouvrez une Pull Request

## 📝 License

Distribué sous la licence MIT. Voir `LICENSE` pour plus d'informations.

## ✍️ Auteur

Votre Nom - [@votre_twitter](https://twitter.com/votre_twitter)

## 🙏 Remerciements

- 📚 La communauté C++ pour son soutien
- 🎨 Windows API pour l'interface graphique
- 🛠️ Tous les contributeurs du projet

---

<div align="center">
  <sub>Built with ❤️ by filox</sub>
</div>
