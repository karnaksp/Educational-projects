DELETE FROM person_order
WHERE (person_id, menu_id, order_date) IN (
        SELECT
            p.id AS person_id,
            m.id AS menu_id,
            DATE '2022-02-25' AS order_date
        FROM person AS p
            JOIN menu AS m ON m.pizza_name = 'greek pizza'
    );

DELETE FROM menu WHERE pizza_name = 'greek pizza'