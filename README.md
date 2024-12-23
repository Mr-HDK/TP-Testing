# TP-Testing

## Description
Ce dépôt contient une série de travaux pratiques destinés aux étudiants en ingénierie des systèmes embarqués (3ème année), visant à explorer les différentes phases du testing logiciel, allant des tests unitaires à l'intégration, et à appliquer ces principes à un projet réel.

Les étudiants apprendront à utiliser des outils de test adaptés au développement en C pour des systèmes embarqués, avec un accent particulier sur les tests unitaires, d’intégration et fonctionnels.  

---

## Objectifs pédagogiques
Les travaux pratiques ont pour objectif de :
- Faire un rappel sur les commandes gits.
- Familiariser les étudiants avec les tests unitaires, d’intégration et fonctionnels.
- Introduire les outils de test couramment utilisés dans le développement embarqué.
- Appliquer les concepts appris à un projet concret dans un environnement embarqué.

---

## Gestion de version avec Git

Pour travailler efficacement sur ce TP et garder votre travail organisé, suivez les étapes ci-dessous. Ces étapes seront valables pour tous les TP. Vous devrez toujours travailler sur votre branche personnelle.

**1. Cloner le dépôt du TP :**

Commencez par cloner le dépôt GitHub contenant le TP à l'aide de la commande suivante :

`git clone https://github.com/Mr-HDK/TP-Testing.git`

Accédez ensuite au dossier du projet :

`cd TP-Testing`


**2. Créer une branche avec votre prénom et nom :** 

Créez une branche pour travailler sur votre copie. Nommez la avec votre prénom et nom (en minuscules et séparés par un tiret) :

`git branch prenom-nom`         
`git checkout prenom-nom`

Remarque : Remplacez prenom-nom par vos vrais prénom et nom (par exemple, ahmed-jaleli). Une fois cette branche créée, vous continuerez à travailler sur cette même branche tout au long des TP. Il n'est pas nécessaire de créer une nouvelle branche à chaque TP.

**3. Travailler sur votre branche :** 

Modifiez les fichiers nécessaires au TP. Après chaque modification importante, ajoutez et commitez vos changements :

`git add .`     
`git commit -m "Début du TP - Ajout de [description]"`

Utilisez des messages de commit clairs et explicites pour chaque étape importante de votre travail.

**4. Sauvegarder et envoyer vos modifications :** Poussez régulièrement vos modifications sur GitHub pour sauvegarder votre progression :

`git push origin prenom-nom`

---

**5. Soumettre votre travail via une Pull Request (PR) :**

Une fois un **TP terminé**, vous créez une Pull Request (PR) pour soumettre votre travail. Voici les étapes à suivre :

1. **Mettez votre branche à jour :**    
Avant de créer une PR, synchronisez votre branche avec la branche principale (main) pour éviter des conflits :  
`git pull origin main`

2. **Créez une PR sur GitHub :**
    - Allez sur le depot et sélectionnez votre branche de travail (`prenom-nom`).
    - Cliquez sur **"Compare & pull request"**.
    - Rédigez une description claire de votre travail et si vous avez des points spécifiques que vous souhaitez que j'examine.
    - Cliquez sur **"Create pull request"**.

3. **Recevez vos retours :**    
Je vais examiner votre PR et laisser des commentaires si nécessaire. Les PR ne seront pas fusionnées dans la branche `main`, elles servent uniquement pour les retours et discussions.

    
---

### Bonnes pratiques de gestion de branche

- **Mettez régulièrement votre branche à jour :**  Pour rester synchronisé avec les dernières modifications du dépôt principal (`main`), utilisez régulièrement : 

    `git pull origin main`

- **Effectuez des commits fréquents :**  
Sauvegardez vos progrès régulièrement avec des messages de commit clairs.

---

## Feedback et communication avec l'instructeur

Pour assurer un suivi efficace, voici comment je fournirai mes retours :

- **Commentaires sur les commits :**  
 Je pourrai laisser des commentaires directement sur vos commits. Consultez-les pour prendre en compte mes retours.

- **Pull Requests (PR) :**  
 À la fin de chaque TP, j'utiliserai vos PR pour fournir des retours détaillés sur votre travail.

- **Issues :**  
 Si vous avez des questions, des problèmes ou besoin de clarifications, utilisez la section **Issues** du dépôt GitHub. Je ferai de mon mieux pour répondre et clarifier vos questions.

---

## TP-1 : Introduction au Testing et Git

Ce premier TP couvre :
- La configuration de votre environnement de travail.
- Les bases et rappels sur les commandes Git essentielles, et la creation de votre branche de travail.
- L'initialisation et l'exécution de tests unitaires dans un environnement C embarqué.


Pour plus de détails sur le TP-1, veuillez consulter [le README du TP-1](TP-1/README.md).

---

### Remarques importantes
- Assurez-vous de consulter le `README.md` de chaque TP pour obtenir des instructions détaillées sur l'installation, la configuration des outils nécessaires et vos tâches.



---
---

<details>

<summary>⚙️ Commandes principales pour git (Cliquez pour dérouler)</summary>

Voici un rappel des commandes Git essentielles que vous utiliserez pour ce processus :

| **Commande** | **Description** |
| --- | --- |
| `git init` | Initialise un nouveau dépôt Git. |
| `git clone <URL>` | Clone un dépôt distant sur votre machine locale. |
| `git checkout -b <branche>` | Crée et bascule sur une nouvelle branche. |
| `git add <fichier>` | Ajoute un fichier ou un répertoire à l'index (préparation avant le commit). |
| `git commit -m "message"` | Crée un commit avec un message décrivant les changements effectués. |
| `git push origin <branche>` | Envoie vos commits locaux vers le dépôt distant sur la branche spécifiée. |
| `git pull origin main` | Récupère les dernières modifications du dépôt distant et les fusionne avec votre branche locale. |

</details>
