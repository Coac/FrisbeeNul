FrisbeeNul
========

## Comment récupérer le projet

### Pré-requis
 - [unreal engine 4.10.4](https://www.unrealengine.com/)
 - [git](https://git-scm.com/downloads)
 - [visual studio](https://www.visualstudio.com/post-download-vs?sku=community&clcid=0x40c) (pensez à installer les [outils courants pour visual c++ 2015](http://puu.sh/o2xgS/e0aa1448ef.png))

### Obtenir votre propre version du projet

Nous allons utiliser le système de fork/pull request afin de gérer les contributions des participants. Cela signifie qu'il existe un dépôt "maître" (celui de SuperCoac) et que chaque participant va créer une copie de ce dépôt qu'il pourra alors gérer comme il le souhaite.

Pour créer votre propre dépôt, cliquez sur le bouton ["fork"](http://puu.sh/o2xUl/52a0f92f17.png) en haut à droite de la fenêtre.

Afin de copier le dépôt en local sur votre machine, choisissez l'emplacement que vous souhaitez et ouvrez une fenêtre de commande (maj + clic droit pour le faire à partir du menu contextuel). Tapez ensuite `git clone https://github.com/votre nom d'utilisateur/FrisbeeNul.git` ce qui effectuera une copie du dépôt sur votre machine a l'emplacement actuel.

Afin de mettre son dépôt à jour, il suffit de faire un `git pull https://github.com/SuperCoac/FrisbeeNul.git`. Dans le cas où vous avez effectué des changements conflictueux avec le dépot maître, il se peut qu'ils soit nécessaire de résoudre des conflits. Nous y viendrons une fois que nous y serons confrontés.

### Ouvrir le projet dans Unreal

Une fois que vous avez récupéré le projet, chercher le fichier `/FrisbeeNul.uproject`, faites un clic droit et cliquez sur '`Generate visual studio project files`.

Lancer ensuite Unreal Engine et ouvrez le projet FrisbeeNul. Unreal va vous demander de rebuild le projet, acceptez. Si vous avez tout bien suivi jusqu'à maintenant, tout devrait se passer sans problème et vous devriez vous retrouver face à un terrain avec un personnage et un cube. Si vous cliquez sur play, vous devriez être en mesure de faire bouger le personnage grâce au clic gauche et si vous appuyez sur `a` près du cube, celui-ci devrait bouger.

Si ce n'est pas le cas, l'erreur la plus probable et que vous ayez oublié d'installer les outils courants pour visual c++ 2015. Vous pouvez les ajouter en passant par la fenêtre programme et fonctionnalités, choisissez visual studio 2015, clic droit -> modifier, une fenetre s'ouvrira alors vous proposant de choisir les différentes extensions que vous voulez installer. Choisissez "outils courants pour visual c++ 2015" et réessayez.

Si vous avez un problème, merci de contacter @Coac/@Citizen v2 sur discord afin que nous puissions vous aider.
