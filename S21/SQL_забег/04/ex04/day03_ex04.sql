WITH female_order AS (
        SELECT pz.name
        FROM person_order AS po
            JOIN person AS p ON p.id = po.person_id
            JOIN menu AS m ON m.id = po.menu_id
            JOIN pizzeria pz ON pz.id = m.pizzeria_id
        WHERE
            p.gender = 'female'
    ),
    male_order AS (
        SELECT pz.name
        FROM person_order AS po
            JOIN person AS p ON p.id = po.person_id
            JOIN menu AS m ON m.id = po.menu_id
            JOIN pizzeria AS pz ON pz.id = m.pizzeria_id
        WHERE
            p.gender = 'male'
    ),
    female_only AS (
        SELECT
            female_order.name
        FROM female_order
        EXCEPT
        SELECT
            male_order.name
        FROM
            male_order
    ),
    male_only AS (
        SELECT
            male_order.name
        FROM male_order
        EXCEPT
        SELECT
            female_order.name
        FROM female_order
    )
SELECT female_only.name
FROM female_only
UNION
SELECT male_only.name
FROM male_only
ORDER BY 1;