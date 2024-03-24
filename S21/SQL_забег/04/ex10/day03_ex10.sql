INSERT INTO person_order
VALUES ( (
            SELECT
                COALESCE(MAX(po.id), 0) + ROW_NUMBER() OVER ()
            FROM
                person_order AS po
        ), (
            SELECT p.id
            FROM person AS p
            WHERE
                p.name = 'Denis'
        ), (
            SELECT m.id
            FROM menu AS m
            WHERE
                m.pizza_name = 'sicilian pizza'
        ),
        DATE '2022-02-24'
    );

INSERT INTO person_order
VALUES ( (
            SELECT
                COALESCE(MAX(po.id), 0) + ROW_NUMBER() OVER ()
            FROM
                person_order AS po
        ), (
            SELECT p.id
            FROM person AS p
            WHERE
                p.name = 'Irina'
        ), (
            SELECT m.id
            FROM menu AS m
            WHERE
                m.pizza_name = 'sicilian pizza'
        ),
        DATE '2022-02-24'
    );

-- DELETE FROM person_order
-- WHERE (person_id, menu_id, order_date) IN (
--         SELECT
--             p.id AS person_id,
--             m.id AS menu_id,
--             DATE '2022-02-24' AS order_date
--         FROM person AS p
--             JOIN menu AS m ON m.pizza_name = 'sicilian pizza'
--         WHERE
--             p.name IN ('Denis', 'Irina')
--     );