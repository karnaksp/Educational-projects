CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date
(IN pperson varchar DEFAULT 'Dmitriy', IN pprice numeric 
DEFAULT 500, IN pdate date DEFAULT '2022-01-08') RETURNS TABLE
("pizzeria_name" varchar) AS 
$$
BEGIN
	RETURN QUERY
	SELECT DISTINCT
	    "pizzeria"."name"
	FROM
	    "person_visits"
	    JOIN "person_order" ON "person_visits"."person_id" = "person_order"."person_id"
	    AND "person_visits"."visit_date" = "person_order"."order_date"
	    JOIN "menu" ON "person_order"."menu_id" = "menu"."id"
	    JOIN "pizzeria" ON "person_visits"."pizzeria_id" = "pizzeria"."id"
	    JOIN "person" ON "person_order"."person_id" = "person"."id"
	WHERE
	    "person"."name" = pperson
	    AND "menu"."price" < pprice
	    AND "person_visits"."visit_date" = pdate;
END;
$$
LANGUAGE
PLPGSQL; 

SELECT * FROM fnc_person_visits_and_eats_on_date (pprice := 800);

SELECT *
FROM
    fnc_person_visits_and_eats_on_date (
        pperson := 'Anna', pprice := 1300, pdate := '2022-01-01'
    );