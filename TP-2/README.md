# TP-2 : Tests d'intégration et analyse de qualité de code

## Objectifs  
1. **Réaliser des tests unitaires :** Assurez-vous que chaque module fonctionne correctement isolément.  
2. **Réaliser des tests d'intégration :** Vérifiez les interactions entre plusieurs modules du code embarqué.  
3. **Analyser la couverture de code :** Générez des rapports de couverture avec `GCOVR`.  
4. **Évaluer la qualité du code :** Identifiez les points d'amélioration avec `cppcheck`.

## Prérequis et installation  
Avant de commencer, assurez-vous que tous les outils nécessaires sont installés.  

### Outils nécessaires (déjà utilisés dans TP-1) :  
- **Ceedling** (framework de tests unitaires)  
- **GCOV/GCOVR** (outils pour la couverture de code)  

### Nouvel outil pour ce TP : Cppcheck  
**Cppcheck** est un outil d'analyse statique qui détecte les erreurs, les problèmes de style et les potentiels bogues dans le code.  

- Installation sous Windows :  
  Téléchargez et installez depuis [ce lien](https://github.com/danmar/cppcheck/releases/download/2.16.0/cppcheck-2.16.0-x64-Setup.msi).  

- Installation sous Linux :  
  `sudo apt-get install cppcheck`

## Contexte  
Dans ce TP, vous travaillerez sur un projet embarqué simulant la gestion d'un capteur de température et des notifications associées. L'objectif est d'aller au-delà des tests unitaires (vus dans TP-1) en effectuant des **tests d'intégration**, qui permettent de valider la collaboration entre plusieurs modules.  

Vous allez également explorer deux aspects importants de la qualité logicielle :  
1. La **couverture de code** pour évaluer l'efficacité de vos tests.  
2. L'**analyse statique** pour identifier les problèmes potentiels dans votre code grâce à Cppcheck.  

## Structure du projet  
- `/src` : Contient les fichiers sources du projet.  
- `/test` : Contient les fichiers de tests unitaires et d'intégration.  
    - test_sensor.c     --> Tests unitaires pour sensor.c
    - test_controller.c --> Tests d'intégration pour controller + sensor
    - test_notifier.c      --> Tests unitaires pour notifier.c
    - test_system.c      --> Tests d'intégration globale
- `/reports` : Contiendra les rapports générés (couverture de code, qualité du code, etc.).     
**NB**: Les rapports générés par *ceedling* seront par défaut dans 'build/artifacts/gcov'

- `/img` : Contiendra les screenshots (y compris les résultats de l'analyse cppcheck, GUI ou CLI)  

## Remarques et Choix Techniques

#### 1. Utilisation d'un Seed pour la Reproductibilité
Dans les tests, la fonction **`read_sensor`** génère des valeurs aléatoires simulant les lectures d'un capteur. Afin d'assurer la reproductibilité des résultats, un **seed fixe** (`srand(42)`) a été utilisé dans les tests. Cela permet de :
- Garantir que la même séquence de valeurs aléatoires est utilisée à chaque exécution des tests, ce qui facilite le débogage.
- Simuler un environnement contrôlé tout en restant réaliste.

**Note :** Il est possible de modifier le seed si vous souhaitez explorer d'autres séquences ou tester des scénarios non déterministes.


#### 2. Choix d’Approche pour `test_system.c`
Le fichier `test_system.c` vise à valider l'intégration globale de tout le pipeline (lecture des capteurs, traitement des données et gestion des notifications). Voici quelques choix techniques expliqués :
- **Pas d’utilisation de Mock pour `sensor.c` :**  
  Bien qu’il soit possible d’utiliser un mock pour `read_sensor` afin de contrôler précisément les valeurs de retour, cela irait à l’encontre de l’objectif des tests d'intégration. Le but ici est de valider l'ensemble du système dans un contexte réaliste, en utilisant les valeurs réellement générées.
  
- **Division des Tests Valid/Invalid :**  
  Les tests ont été divisés en deux workflows distincts :
  - **`test_valid_sensor_value_workflow` :** Vérifie uniquement les cas valides, simplifiant ainsi la détection d'éventuelles erreurs dans le traitement des données valides.
  - **`test_invalid_sensor_value_workflow` :** Se concentre exclusivement sur la gestion des cas invalides, tels que les notifications déclenchées pour des valeurs hors plage.
  
  Cette séparation améliore la lisibilité, facilite le diagnostic en cas d’échec, et permet une couverture ciblée.


#### 3. Tests de Cas Limites
Les bordures critiques (`0`, `100`, `-1`, `101`, `149`) sont injectées manuellement dans certains tests, notamment dans **`test_boundary_conditions`**, afin de compléter les scénarios aléatoires générés par `read_sensor`. Ce choix garantit que :
- Les comportements du système sont explicitement vérifiés pour des cas limites.
- Les tests restent robustes, même si `read_sensor` ne génère pas certaines bordures spécifiques.


## Étapes du TP  
1. **Étude du code source :** Comprenez la structure et le fonctionnement des modules fournis.
2. **Écriture des tests :** Rédigez des tests unitaires et d'intégration pour couvrir un maximum de cas.
3. **Génération des rapports de couverture :** Comparez les résultats obtenus avec `GCOV` et `GCOVR`.  
4. **Analyse de la qualité du code :** Utilisez un outil comme `cppcheck` pour générer un rapport détaillé.

## Commandes utiles  
- **Exécuter tous les tests :**  
  `ceedling test:all`

- **Générer un rapport GCOVR :**  
  `ceedling gcov:all`  
  `ceedling utils:gcov`  
  `gcovr --html-details reports/coverage.html`

- **Lancer une analyse cppcheck :**  
  `cppcheck --enable=all --inconclusiv src/ > reports/cppcheck_report.txt`
  Ou bien en utilisant cppcheck GUI

## Travail demandé  
1. Écrivez les tests nécessaires dans le dossier `test/`.  
2. Configurez le fichier `project.yml`.
3. Générez des rapports de couverture avec GCOVR et GCOV.  
4. Analysez le code avec cppcheck et proposez des corrections si nécessaires. (vous pouvez également utiliser un autre code C/C++ de votre choix à analyser).
5. Ajoutez des captures d'écran dans le dossier `img/`.
6. Soumettez votre travail sous forme de Pull Request sur GitHub.
