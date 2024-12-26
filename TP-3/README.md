# TP-3 : Tests Système avec Robot Framework et Python

## Objectif
L'objectif de ce TP est d'explorer la mise en place de tests **système** en utilisant **Robot Framework** avec Python. Ce TP permet de tester un système simulé dans lequel plusieurs modules interagissent ensemble.

Le but est de tester un système embarqué où plusieurs composants (capteur de température, actionneur, contrôleur, notificateur) sont simulés dans le code, et de vérifier leur bon fonctionnement via des tests système.

---

## Prérequis

### Outils nécessaires
1. **Python 3.x**  
   Vérifiez que Python est installé avec :  
   `python3 --version`  

2. **Installer les dépendances du projet**  
   Dans le répertoire du projet, exécutez :  
   `pip install -r requirements.txt`  

---

## Structure du projet

Le projet est organisé comme suit :

``` bash

/TP-3
├── src/ # Fichiers sources Python simulant le système embarqué
│ ├── actuator.py # Gère l'activation du chauffage ou du ventilateur
│ ├── config.py # Configuration globale (seuils de température)
│ ├── controller.py # Contrôle la logique métier basée sur la température
│ ├── logger.py # Journalisation des actions et événements
│ ├── notifier.py # Gère les notifications en cas de température critique
│ ├── sensor.py # Simule la lecture de la température depuis un capteur
│ └── utils.py # Fonctions utilitaires (validation)

├── test/ # Répertoire contenant les tests Robot Framework
│ ├── resources/ # Mots-clés et variables réutilisables
│ │ └── keywords.robot # Mots-clés centralisés
│ │
│ ├── suites/ # Suites de tests organisées par type
│ │ ├── functional_tests.robot # Tests fonctionnels : actions système
│ │ ├── validation_tests.robot # Tests de validation des températures
│ │ ├── alert_tests.robot # Tests des notifications hors plage
│ │
│ ├── test_system.robot # Tests système généraux (validations et actions)
│ ├── test_e2e_45.robot # Test E2E pour 45°C
│ └── test_temperature_critical.robot # Scénario critique à compléter par les étudiants

├── requirements.txt # Dépendances Python pour le projet
└── README.md # Documentation du projet
```

- **src/** : Simulation du système (capteurs, contrôleur, etc.).
- **test/** : Tests automatisés avec Robot Framework.
- **resources/** : Contient les mots-clés centralisés.
- **test_temperature_critical.robot** : Exercice destiné aux étudiants pour implémenter un cas de test.


---

## Étapes pour Exécuter les Tests

1. **Cloner le projet**  
   `git clone https://github.com/Mr-HDK/TP-Testing`  
   `cd TP-3`  
   Ou bien **Récupérer la dernière version du projet**
   `git pull origin main`

2. **Installer les dépendances**  
   `pip install -r requirements.txt`  

3. **Exécution des tests**  
   *  Exécuter tous les tests :    
      Pour exécuter l’ensemble des tests dans le répertoire :   
      
      `robot test/`

   *  Exécuter toutes les suites :     
      Pour exécuter uniquement les tests dans le répertoire suites/ :

      `robot test/suites/`

   *  Exécuter un test spécifique :    
      Exemple pour exécuter uniquement le test test_temperature_critical.robot :

      `robot test/test_temperature_critical`

4. **Consulter les rapports**  
   Les résultats des tests seront disponibles ici :  
   `test/results/report.html`    
   **NB:** Contient un **apercu détaillé** des tests.

---

## Détails des Tests

### 1. **Tests Système**
- **`test_system.robot`** : Vérifie les fonctionnalités de base :  
  - Lecture de températures (valide et invalide).  
  - Activation du chauffage ou du ventilateur en fonction de la température.  
  - Notifications pour températures hors seuil.

### 2. **Test E2E Température Fixe**
- **`test_e2e_45.robot`** : Scénario complet avec une température de **45°C** :  
  - Validation de la température.  
  - Activation du ventilateur.  
  - Vérification qu'aucune notification n'est envoyée.

### 3. **Test Température Critique (Travail pour les Étudiants)**
- **`test_temperature_critical.robot`** :  
   **Scénario à implémenter** :  
   - Fixer la température à **120°C**.  
   - Vérifier que la température est invalide.  
   - Aucune action ne doit être prise (chauffage ou ventilateur).  
   - Une notification critique doit être envoyée.  
   - Documenter chaque étape avec des logs.

---

## Étapes Pratiques pour les Étudiants

1. **Corriger les Tests Existants**  
   - Assurez-vous que **`test_system.robot`** et **`sensor.py`** sont corrigés pour ne générer aucune erreur (aucun test échoué) dans tous les scénarios.

2. **Compléter le Scénario Température Critique**  
   - Implémentez le fichier **`test_temperature_critical.robot`** pour vérifier le comportement du système avec une température critique :  
     - Fixez la température à **120°C**.  
     - Validez que la température est invalide.  
     - Aucune action (chauffage ou ventilation) ne doit être prise.  
     - Une notification critique doit être envoyée.

3. **Executer tous les tests**
   - Lancez l’exécution de tous les tests pour vous assurer qu’aucune erreur n’est présente. (Corriger les erreurs.)
   - Exécutez spécifiquement le fichier `test_temperature_critical.robot` et vérifiez que le scénario se déroule comme prévu.

4. **Documenter les Résultats**
   - Prenez des captures d’écran des résultats dans le terminal (CLI) pour l’exécution complète des tests.
   - Prenez des captures d’écran du rapport HTML détaillé généré pour `test_temperature_critical.robot`

---

### Bonus (Optionnel)
- **Simuler des Capteurs Défectueux**  
   - Modifiez **`sensor.py`** pour retourner des valeurs `None` ou des températures hors plage comme **-100°C**.  
   - Ajoutez un test pour vérifier que le système logue correctement une erreur ou ignore ces valeurs.
- Générer des rapports de tests automatiques dans un fichier CSV.

---

## Ressources Utiles

- [Robot Framework Documentation](https://robotframework.org/robotframework/)  
- [Guide des Tests E2E avec Robot](https://robotframework.org/#example-tests)  
- [Examples de tests avec Robot (web)](https://docs.robotframework.org/docs/examples/overview)
- [Installer Python et pip](https://pip.pypa.io/en/stable/)

---

