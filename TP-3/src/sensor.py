import random
 """
def read_temperature(custom_value=None):
   
   # Simule la lecture d'une température par un capteur.
   # Si une valeur personnalisée est fournie, elle est utilisée.
   # Sinon, retourne une température aléatoire dans la plage [0, 150]°C.
  
    if custom_value is not None:
        return float(custom_value)
    return random.uniform(0, 150)  # Dépasse la plage valide [0, 100]°C 
                                   # à vous de la changer.
                                   
"""


def read_temperature(custom_value=None):
    """
   # Simule la lecture d'une température par un capteur.
    #- Retourne `custom_value` si elle est fournie.
    #- Sinon, retourne une température aléatoire dans une plage étendue ou `None`.
    """
    if custom_value is not None:
        return float(custom_value)
    
    # Génère aléatoirement None, une température hors plage ou une température valide
    scenarios = [None, random.uniform(-100, -1), random.uniform(0, 100), random.uniform(101, 150)]
    return random.choice(scenarios)

