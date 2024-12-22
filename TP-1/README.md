TP-1 : Tests Unitaires en C avec Ceedling
=========================================

Objectifs
---------

-   Créer une structure de projet Ceedling pour les tests unitaires en C.
-   Écrire des tests unitaires pour des fonctions simples.
-   Exécuter et analyser les résultats des tests unitaires.
-   Réviser les bases de Git dans un contexte pratique.

* * * * *

Structure du projet
-------------------

-   **`src/`** : Contient les fichiers sources de l'application à tester.
-   **`tests/`** : Contient les fichiers de tests unitaires.
-   **`TP-1/README.md`** : Ce fichier contient les instructions pour cette séance.
-   **`exercice-avancé`** : Contient un exercice supplémentaire à réaliser.

* * * * *

Rappel sur Git
--------------

### Étapes pour gérer votre projet avec Git

Pour travailler efficacement sur ce TP, suivez les étapes ci-dessous.

* * * * *

### 1\. Cloner le dépôt du TP

Commencez par cloner le dépôt GitHub contenant le TP :

`git clone https://github.com/Mr-HDK/TP-Testing-3ISEOC.git`

Une fois le dépôt cloné, accédez au dossier du projet :

`cd TP-Testing-3ISEOC`

* * * * *

### 2\. Créer une branche avec votre prénom et nom

Créez une branche pour travailler sur votre copie en utilisant votre prénom et nom (par exemple, `ahmed-jaleli`) :

`git branch prenom-nom`

`git checkout prenom-nom`

> **Remarque :** Remplacez `prenom-nom` par vos vrais prénom et nom, en utilisant des lettres minuscules et un tiret pour séparer les mots (par exemple, ahmed-jaleli).

* * * * *

### 3\. Travailler sur votre branche

1.  Modifiez les fichiers nécessaires au TP.
2.  Ajoutez vos modifications au suivi de Git :
   
    `git add .`
3.  Sauvegardez vos changements avec un message clair :
   
    `git commit -m "Début du TP - Ajout de [description]"`

* * * * *

### 4\. Mettre à jour votre branche:

**_Si_** des modifications sont apportées par l'instructeur au dépôt principal (main), vous pouvez facilement récupérer ces changements tout en restant sur votre branche. Pour cela, utilisez cette commande :

1.  **Depuis votre branche**, récupérez les derniers changements du dépôt principal :
   
   `git pull origin main`

Cela mettra à jour votre branche avec les dernières modifications de la branche main sans avoir besoin de passer par des étapes supplémentaires.

### 5\. Sauvegarder et envoyer vos modifications

Une fois que vous avez terminé une partie de votre travail, il est important de pousser régulièrement vos changements sur GitHub pour ne pas perdre votre progression.

1. Pousser vos changements sur votre branche GitHub :

   `git push origin prenom-nom`

Cela permet de sauvegarder vos modifications dans le dépôt distant tout en restant sur votre propre branche.

* * * * *

### Commandes principales à retenir :

| Commande | Description |
| --- | --- |
| `git clone [URL]` | Cloner un dépôt Git distant. |
| `git branch prenom-nom` | Créer une nouvelle branche. |
| `git checkout prenom-nom` | Passer sur une branche spécifique. |
| `git add .` | Ajouter toutes les modifications au suivi de Git. |
| `git commit -m "message"` | Sauvegarder les modifications avec un message. |
| `git pull origin main` | Récupérer les changements du dépôt principal. |
| `git fetch origin` | Récupérer les changements du dépôt distant sans les fusionner. |
| `git merge main` | Fusionner une branche dans la branche actuelle. |


🛠️ Préparation des outils
--------------------------

### Prérequis

Les étudiants doivent disposer des outils suivants pour suivre ces travaux pratiques :

-   Un éditeur de code comme VS Code ou tout autre éditeur de texte adapté.
-   Un compilateur C (par exemple, GCC ou MinGW sur Windows).
-   Git pour la gestion de version.
-   Ruby et Ceedling pour les tests unitaires.

* * * * *

### Installation des outils

#### Pour Linux :

-   **Installer Git** :

    `sudo apt update`
    
    `sudo apt install git`

-   **Installer le compilateur C** :

    `sudo apt install build-essential`

-   **Installer Ruby** :

    `sudo apt install ruby-full`

-   **Installer Ceedling** :

    `gem install ceedling`

    Consultez les détails concernant le problème d'installation de Ceedling et sa résolution dans la section ci-dessous : [Problèmes d'installation de Ceedling](#problème-avec-ruby-31-et-versions-ultérieures).


#### Pour Windows :

-   **Installer Git** depuis [Git pour Windows](https://git-scm.com/).
-   **Installer le compilateur C avec MinGW** :
    -   Téléchargez et installez MinGW.
    -   Ajoutez le chemin du dossier `bin` à vos variables d'environnement.
-   **Installer Ruby** depuis [RubyInstaller](https://rubyinstaller.org/). [**_Version 3.0.X recommandée_**](https://github.com/oneclick/rubyinstaller2/releases/download/RubyInstaller-3.0.7-1/rubyinstaller-devkit-3.0.7-1-x64.exe)
    -   Assurez-vous d'inclure DevKit et d'ajouter Ruby au PATH.
-   **Installer Ceedling** :

    `gem install ceedling`

 Consultez les détails concernant le problème d'installation de Ceedling et sa résolution dans la section ci-dessous : [Problèmes d'installation de Ceedling](#problème-avec-ruby-31-et-versions-ultérieures).

* * * * *

### Vérification des installations

-   **Vérifiez Git** :

    `git --version`

-   **Vérifiez le compilateur C** :

    `gcc --version`

-   **Vérifiez Ruby** :

    `ruby --version`

-   **Vérifiez Ceedling** :

    `ceedling version`

    #### Problème avec Ruby 3.1 et versions ultérieures

<details>
   
  <summary>Problèmes d'installation de Ceedling (Version 0.31.1)</summary>


Si vous utilisez Ceedling version 0.31.1, il est important de rester avec la version majeure et mineure de Ruby utilisée lors du développement de cette version de Ceedling. Pour la version 0.31.1, il est recommandé d'utiliser Ruby 3.0.x.

Les versions de Ruby 3.1.0 et ultérieures peuvent causer des problèmes, notamment l'erreur suivante :
undefined method `exists?' for class File (NoMethodError)

### Solutions possibles

1. **Utiliser une version compatible de Ruby** :
   - Si possible, rétrogradez vers Ruby 3.0.x, qui est la version compatible avec Ceedling 0.31.1.
   
2. **Modifier le code source de Ceedling** :
   Si la mise à jour de Ruby ne résout pas le problème, vous pouvez modifier manuellement le fichier source de Ceedling pour remplacer `File.exists?` par `File.exist?`.

   **Étapes à suivre** :
   1. Ouvrez le fichier `C:/Ruby33-x64/lib/ruby/gems/3.3.0/gems/ceedling-0.31.1/bin/ceedling` avec un éditeur de texte.
   2. Remplacez toutes les occurrences de `File.exists?` par `File.exist?`.
   3. Sauvegardez le fichier et réessayez la commande `ceedling version`.

   Si cela ne résout toujours pas le problème, vous pouvez également essayer de modifier un autre fichier source :

   1. Ouvrez le fichier `C:/Ruby33-x64/lib/ruby/gems/3.3.0/gems/ceedling-0.31.1/lib/ceedling/version.rb`.
   2. Remplacez toutes les occurrences de `File.exists?` par `File.exist?` dans ce fichier.
   3. Sauvegardez les modifications et réessayez d'exécuter la commande `ceedling version`.

Cela devrait résoudre le problème lié à la méthode `File.exists?`.

Pour plus de détails sur ce problème, vous pouvez consulter la discussion suivante sur [Google Groups](https://groups.google.com/g/throwtheswitch/c/0KwIzBcemH4/m/Jm8Yv_x-BAAJ).

</details>


* * * * *

Étapes principales pour le TP
-----------------------------

1.  **Créer un projet Ceedling** :

    `ceedling new .`

2.  **Modifier le fichiers de test** dans le répertoire `/tests/`.

3.  **Exécuter vos tests unitaires** :

    `ceedling test:all`
    
4. **Prendre des captures d'écran de votre terminal** :

-   Après la création du projet (structure du dossier).
-   Après l'exécution des tests (résultats des tests).

5. **Créer un dossier** `/img` dans le répertoire du projet et y ajouter les captures d'écran.

6.  **Pousser vos changements sur GitHub** :

    `git add .`
    
    `git commit -m "Ajout des fichiers du TP-1 et [description..]"`
    
    `git push origin prenom-nom`

* * * * *

🚩 À la fin du TP-1
-------------------

À la fin de cette première séance, vous aurez :

-   Une meilleure maîtrise de Git en contexte réel.
-   Un projet Ceedling fonctionnel.
-   Des tests unitaires exécutés avec succès.

* * * * *

🎯 Étape suivante : [Concepts avancés](./exercice-avancé)

Explorez le dossier **/exercice-avancé** pour :

- Découvrir des exemples concrets de fonctions à tester avec des mocks.
- Utiliser les extensions/plugins pour optimiser vos tests.
- Travailler sur un nouveau défi technique lié aux systèmes embarqués.

* * * * *
