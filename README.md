# To Do

Mettez vos noms à coté des tâches que vous voulez faire!

1. [Programmation](#programmation) 
   1. [Capteurs](#capteurs)
       1. [Altimètre (Aurélie)](#altimètre)
       2. [IMU (Aurélie)](#imu)
       3. [Capteur Temp (Fernando)](#capteur-temp)
       4. [Acceleromètre (Alex)](#acceleromètre)
       5. [GPS SRAD ()](#gps-srad)
       6. [Carte SD (Aurélie)](#carte-sd)
          
   1. [Détection d'obstacles + Mappage (Alex + )](#détection-dobstacles-et-mappage)
   2. [Système de mouvement ()](#système-de-mouvement)
   1. [Flight Modes](#flight-modes)
        1. [Pre Flight ()](#pre-flight)
        2. [Flight ()](#flight)
        3. [Post Flight ()](#post-flight)
       
   



3. [Design PCB](#design-pcb)


## Programmation 

Pour la prog: STM32CubeIDE, STM32CubeMX, GitHub Desktop & le repo est le Rover_Firmware dans la même organisation. 

Rappel faire une branche pour chaque nouvelle fonctionnalité developpé. 

Il est important que les capteurs fonctionnent en 1er dans le but de pouvoir programmer toutes les fonctionnalités voulues. 

------
### Capteurs


Pour les capteurs voici un petit guideline pour la programmation à suivre pour assurer le fonctionnement des capteurs. (Si besoin d'inspiration checker les fonctions faites pour les autres capteurs)
- Communiquer avec (I2C/SPI etc)
- Tester la communication (indicateurs)
- Reçevoir les données et les stocker (Buffer or else)

#### *Altimètre*
L'altimètre est un MS583702BA01-50

#### *IMU*
Le IMU est un BNO055. Il contient le gyroscope aussi

#### *Capteur Temp*
Le capteur de temperature est MAX6612MXK 

#### *Acceleromètre*
L'acceleromètre est un ADXL382-2BCCZ-RL7

#### *GPS SRAD*
Le GPS est un L76LM33

#### *Carte SD*
Le module pour plug la carte SD n'est pas encore choisi parcontre la méthode pour enregistrer des données va être par du FATFS

-----

### Détection d'obstacles et Mappage
Pour le système de détection d'obstacles le LiDar utilisée est un TF-Luna. Pour plus d'information sur cette partie du projet checker la conversation Teams. Sam a envoyé un excellent message.

-----

### Système de mouvement

Pour le système de mouvement il faut controller les servos.
- Être capable de les activer/désactiver
- Ajouter un compteur de tour
- Ajout de détection de surtension/surintensité

-----

### Flight Modes

Voici les points pour les flight modes en ce qui concerne le Rover

#### Pre Flight
- Initialisation des sous-systèmes
- Test des communications internes
- Calibration des capteurs
- Vérification du niveau de batterie et des tensions
- Vérification de la capacit´e de stockage
- Enregistrement d’un pre-flight log (date, capteurs détectés, etc.)
- Mise en veille contrôlée jusqu’à détection du lancement
- Passage en mode veille pour la cam´era hyperspectrale

#### Flight
- Interdiction de mouvement du rover
- Enregistrement des données des différents capteurs sur la carte SD
- Journalisation des événements importants
- Activation des caméras de footage pour la descente (apogée)

#### Post Flight

- Enregistrement des données environnementales
- Activation du système de mouvement et du système de détection d’obstacles
- Prise des données des capteurs + Enregistrement SD 

-----

## Design PCB

Pour le design des PCB
- Finir Diagramme fonctionnel
- Setup KiCad 
