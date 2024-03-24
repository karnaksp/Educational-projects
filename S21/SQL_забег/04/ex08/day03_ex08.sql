INSERT INTO
    menu (
        id,
        pizzeria_id,
        pizza_name,
        price
    )
VALUES ( (
            SELECT MAX(id) + 1
            FROM menu
        ), (
            SELECT id
            FROM pizzeria
            WHERE
                NAME = 'Dominos'
        ),
        'sicilian pizza',
        900
    );

-- DELETE FROM menu WHERE pizza_name = 'sicilian pizza';