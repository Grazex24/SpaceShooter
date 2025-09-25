# 🚀 Space Shooter - Unreal Engine (C++ & Blueprint)

Un projet de type *Shoot'em up 2D*, réalisé avec **Unreal Engine 5**, combinant **C++** et **Blueprints**.  
Le joueur contrôle un vaisseau spatial qui doit survivre face à des astéroïdes.

---

## 📌 Fonctionnalités principales

- 🎮 **Contrôle du vaisseau**
  - Déplacement libre en 2D (haut/bas/gauche/droite).
  - Tir de lasers avec input joueur.
  - Gestion des vies.

- 🪨 **Astéroïdes**
  - Spawn aléatoire depuis une plateforme.
  - Taille aléatoires.
  - Changement de sprite selon l’état de vie.
  - Explosion à la destruction.
  - Disparaissent après un temps aléatoire.

- 🖥 **Interface utilisateur (Widgets)**
  - Affichage du **score** (mise à jour automatique à chaque destruction d'astéroïde).
  - Affichage du **nombre de vies**.
  - Menu principal (MainMenu).
  - Transition entre le menu et le niveau principal.

---

## 🛠 Technologies utilisées

- **Unreal Engine 5** (Paper2D + Niagara).
- **C++** pour la logique de jeu (PlayerState, Spawner, Asteroids, Projectiles).
- **Blueprints** pour l’UI et certains réglages visuels.
- **UMG (Widgets)** pour l’interface score/vies.

---

## 📂 Structure du projet (simplifiée)

Source/
├── Space_Invaders/
│ ├── Public/
│ │ ├── Spaceship.h
│ │ ├── Asteroid.h
│ │ ├── AsteroidSpawner.h
│ │ ├── Spaceshooter_PlayerState.h
│ │ └── Laser.h
│ └── Private/
│ ├── Spaceship.cpp
│ ├── Asteroid.cpp
│ ├── AsteroidSpawner.cpp
│ ├── Spaceshooter_PlayerState.cpp
│ └── Laser.cpp
Content/
├── Sprites/ (sprites Paper2D pour astéroïdes et vaisseau)
├── UI/ (WBP_Score, WBP_Lives, MainMenu)
├── FX/ (explosions, trails)
└── Levels/ (MainMenu, MainLevel)

---

## 🎮 Commandes (par défaut)

- **Z / Flèche haut** → Monter
- **S / Flèche bas** → Descendre
- **Q / Flèche gauche** → Gauche
- **D / Flèche droite** → Droite
- **Clic gauche** → Tirer

---

## 👤 Auteur

Projet réalisé par **Grazex** avec **Unreal Engine 5** en C++ et Blueprints.  