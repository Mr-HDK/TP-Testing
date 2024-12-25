# Exercice Avancé - TP-1  Unit Test

Bienvenue dans l'exercice avancé de testing avec Ceedling, Unity, GCovr et CMock. Cet exercice a pour objectif d'approfondir vos compétences en tests unitaires, génération de mocks, et assertion de comportements.

---

## 🎯 Objectifs

- Découvrir les commandes courantes pour Ceedling, Unity, et CMock.
- Apprendre à intégrer la couverture de code avec GCovr.
- Appliquer des techniques avancées de test avec des mocks et des assertions spécifiques.
- Résoudre un cas pratique pour simuler et valider des interactions complexes.

---

## 🚀 Étapes principales

### 1. Création du projet avec Ceedling

- Créez un nouveau projet avec Ceedling :
  ceedling new .

- Accédez au dossier du projet nouvellement créé :
  cd exercice-avancé

  - Modifiez le fichier `project.yml` pour inclure le plugin GCov :
  :plugins:
    - gcov

### 3. Ajouter des tests avec mocks

- Modifiez le fichier de test pour utiliser des mocks avec CMock.
- Assurez-vous que toutes les dépendances externes sont simulées avec des fonctions comme :

  `mock_reset()`
  `mock_verify()`
  `func_ExpectAndReturn()`
  
### 4. Exécuter les tests et générer un rapport

- Lancez tous les tests :
  
  `ceedling test:all`

- Générez un rapport de couverture :
  
  `ceedling gcov:all`

### 5. Documenter les résultats

- Capturez des captures d’écran des résultats.
- Enregistrez-les dans un dossier `/img` sous le dossier `/exercice-avancé`.

### 6. Poussez votre travail

- Ajoutez et validez vos changements :
  
   `git add .`
  
   `git commit -m "Finalisation des tests unitaires et rapport de couverture"`
  
-  Poussez votre travail sur votre branche
  
   `git push origin prenom-nom`


---

## 📖 Explication : Pourquoi utiliser des mocks ?

Les mocks permettent de simuler des dépendances externes, comme les capteurs ou bases de données, pour isoler les tests unitaires. Cela permet :
- De s'assurer que le module testé est la seule source de défaillance.
- D'éviter les effets secondaires liés à des dépendances externes non fiables.
- De simuler des scénarios difficiles à reproduire dans des environnements réels.

---


## 🚀 Astuce : Utiliser CMock efficacement

CMock est utilisé pour simuler des dépendances externes dans vos tests. Voici un aperçu rapide :

1. **Génération des mocks** :
   - Les mocks sont générés automatiquement pour les dépendances spécifiées dans le fichier `project.yml`.

2. **Réinitialisation et vérification** :
   - Avant chaque test, utilisez `mock_reset()` pour vous assurer qu'il n'y a pas d'interférences.
   - Après le test, utilisez `mock_verify()` pour confirmer que tous les appels attendus ont été faits.

---


## 📋 Tâches à accomplir

1. Créer un projet Ceedling et configurer GCovr.
2. Ajouter des tests avec des mocks pour couvrir tous les cas limites.
3. Exécuter les tests et générer un rapport de couverture.
4. Documenter les résultats avec des captures d’écran, et les sauvegarder dans `/img`.
5. Pousser vos travaux sur votre branche.

---

<details>
   
<summary><strong>⚙️ Commandes utiles (Cliquez pour dérouler)</strong></summary>


Voici une liste de commandes que vous pouvez utiliser dans ce projet :

| **Outil**         | **Commande**                      | **Description**                                                                              |
|--------------------|-----------------------------------|----------------------------------------------------------------------------------------------|
| **Ceedling**       | `ceedling new PROJECT_NAME`       | Crée un nouveau projet Ceedling dans le dossier `PROJECT_NAME`.                              |
|                    | `ceedling test:all`              | Exécute tous les tests présents dans le projet.                                              |
|                    | `ceedling version`               | Affiche la version actuelle de Ceedling installée.                                           |
|                    | `ceedling help`               | Afficher l'aide pour Ceedling.                                           |
|                    | `ceedling clobber`               | Effacer touts els fichiers générés.                                           |
|                    | `ceedling summary`               | Affiche un résumé des résultats des tests exécutés.                                        |
| **Unity**          | `TEST_ASSERT(condition)`         | Vérifie qu'une condition est vraie.                                                         |
|                    | `TEST_ASSERT_FALSE(condition)` | Vérifie qu'une condition est fausse.                                |
|                    | `TEST_ASSERT_EQUAL(expected, actual)` | Vérifie que les valeurs `expected` et `actual` sont égales.                                |
|                    | `TEST_ASSERT_NULL(pointer)`       | Vérifie que le pointeur est nul.                                                            |
|                    | `TEST_ASSERT_EQUAL_INT(expected, actual)` |Compare deux entiers en affichant les erreurs en tant qu'entiers signés.                                |
|                    | `TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual)` | Vérifie qu'une valeur flottante est dans une plage spécifiée autour de la valeur attendue.                                |
|                    | `TEST_ASSERT_NOT_NULL(pointer)`   | Vérifie que le pointeur n'est pas nul.                                                      |
|                    | `TEST_FAIL()`                    | Force l'échec d'un test avec un message optionnel.                                          |
| **CMock**          | `mock_function()`                | Génère un mock pour une fonction externe.                                                   |
|                    | `mock_reset()`                   | Réinitialise tous les appels mockés pour éviter les interférences entre tests.              |
|                    | `mock_verify()`                  | Vérifie si les appels attendus ont été effectués.                                           |
|                    | `func_Expect(expected_params)	`                  | Attend un appel à la fonction avec des arguments spécifiques.                                           |
|                    | `func_ExpectAnyArgs()	`                  | Attend un appel à la fonction sans vérifier les arguments.                                           |
|                    | `func_AddCallback(callback)	`                  | Appelle un callback personnalisé pour remplacer le comportement du mock.                                           |
|                    | `func_ExpectAndThrow(params, error)`                  | Simule une exception lors de l'appel d'une fonction.                                          |

</details>

---

<details>
   
<summary><strong>🛠️ Optionnel : Utiliser l'extension Ceedling Test Explorer dans VS Code (Cliquez pour dérouler)</strong></summary>


Pour simplifier l'exécution et la gestion des tests, vous pouvez installer l'extension **Ceedling Test Explorer** dans Visual Studio Code. Cette extension permet de :
- Visualiser tous vos tests dans une interface conviviale.
- Exécuter les tests directement depuis la barre latérale de VS Code.
- Analyser les résultats des tests rapidement grâce à un résumé clair.

#### Installation :
1. Ouvrez l’onglet des extensions dans VS Code (Ctrl+Shift+X).
2. Recherchez **Ceedling Test Explorer**.
3. Cliquez sur **Install** pour l'ajouter à votre environnement.

#### Interface de l'extension :
Voici un aperçu de l'extension en action :

![Screenshot 2024-11-26 040245](https://github.com/user-attachments/assets/1c3b5d91-bcc7-480d-98df-57390e1b702f)

---

#### Remarque :
L'utilisation de cette extension est **optionnelle**, mais elle peut considérablement améliorer votre expérience avec Ceedling dans VS Code.

</details>

---

## 📚 Références

Pour plus de détails, consultez :
- [GCovr Documentation](https://gcovr.com/en/stable/)
- [Ceedling GCov Plugin](https://github.com/ThrowTheSwitch/Ceedling/tree/master/plugins/gcov)
- [CMock Summary](https://github.com/ThrowTheSwitch/CMock/blob/master/docs/CMock_Summary.md)
- [Unity Framework](https://github.com/ThrowTheSwitch/Unity/tree/master)
- [Ceedling Documentation](https://github.com/ThrowTheSwitch/Ceedling/tree/master/docs)

Ce code source a été généré à l'aide de ChatGPT afin de vous fournir un cas concret et réaliste adapté à un système embarqué. Il a ensuite été modifié et simplifié pour une meilleure testabilité et compréhension pédagogique.

Pour explorer davantage d'exemples pratiques sur les tests avec Unity, consultez :

[Exemples Unity Tests](https://github.com/ThrowTheSwitch/Unity/tree/master/examples)


