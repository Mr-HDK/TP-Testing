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
2. Configurez le fichier `project.yml`.<>
3. Générez des rapports de couverture avec GCOVR et GCOV.  
4. Analysez le code avec cppcheck et proposez des corrections si nécessaires. (vous pouvez également utiliser un autre code C/C++ de votre choix à analyser).
5. Ajoutez des captures d'écran dans le dossier `img/`.
6. Soumettez votre travail sous forme de Pull Request sur GitHub.
