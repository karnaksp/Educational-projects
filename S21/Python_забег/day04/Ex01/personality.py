from random import randint


def turrets_generator():

    def shoot(self):
        print('Shooting')

    def search(self):
        print('Searching')

    def talk(self):
        print('Talking')

    class_name = 'Turret'

    def create_turret_class():
        nonlocal class_name
        personality_traits = [randint(0, 100)]
        personality_traits.append(randint(0, 100 - sum(personality_traits)))
        personality_traits.append(randint(0, 100 - sum(personality_traits)))
        personality_traits.append(randint(0, 100 - sum(personality_traits)))
        return type(
            class_name, (), {
                'name': class_name,
                'shoot': shoot,
                'search': search,
                'talk': talk,
                'neuroticism': personality_traits[0],
                'openness': personality_traits[1],
                'conscientiousness': personality_traits[2],
                'extraversion': personality_traits[3],
                'agreeableness': 100 - sum(personality_traits)
            })

    while True:
        yield create_turret_class()


if __name__ == "__main__":
    for t, i in zip(turrets_generator(), range(5)):
        print('Turret', i, ':', t)
        t.shoot(t)
        t.search(t)
        t.talk(t)
        print('neuroticism:', t.neuroticism)
        print('openness:', t.openness)
        print('conscientiousness:', t.conscientiousness)
        print('extraversion:', t.extraversion)
        print('agreeableness:', t.agreeableness)
        print(
            'personality traits sum:', t.neuroticism + t.openness +
            t.conscientiousness + t.extraversion + t.agreeableness)
        print()
