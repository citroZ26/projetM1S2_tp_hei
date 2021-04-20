# TP HEI
## Objectif : 
Le but de ce TP est de comprendre et utiliser la technologie LoRaWAN dans un scénario plausible. Il s'agit ici de contrôler l'ouverture d'une porte en recensant au serveur les passages. Un premier capteur à l'entrée de la porte comprendra un lecteur RFID. Si l'ID scanné est autorisé ou non, celui-ci enverra un log au serveur comme tentative d'ouverture. De l'autre coté de la porte se situe un capteur de proximité afin de détecter tout passage et le recenser également au serveur. En théorie, le capteur n'est pas en mesure de détecter si le passage est entrant ou sortant, nous enverrons par défaut tout passage.
## Matériels :
- Seeeduino LoRaWAN
- Lopy4 (+ Antenne)
- 2 câbles micro USB
- Station de développement Pycom
- Capteur DHT
- Lecteur RFID
## Code à fournir:
