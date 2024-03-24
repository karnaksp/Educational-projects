CREATE OR REPLACE PROCEDURE create_index_if_not_exists
(IN index_name VARCHAR, IN table_name VARCHAR, IN column_name 
VARCHAR) 
LANGUAGE plpgsql AS 
$$
BEGIN
	IF NOT EXISTS (
	    SELECT 1
	    FROM pg_indexes
	    WHERE
	        indexname = index_name
	) THEN
	EXECUTE format(
	    'CREATE INDEX %I ON %I(%I)', index_name, table_name, column_name
	);
END
	IF;
END;
$$; 

CALL create_index_if_not_exists (
    'idx_menu_pizzeria_id', 'menu', 'pizzeria_id'
);

CALL create_index_if_not_exists (
    'idx_person_order_menu_id', 'person_order', 'menu_id'
);

CALL create_index_if_not_exists (
    'idx_person_order_person_id', 'person_order', 'person_id'
);

CALL create_index_if_not_exists (
    'idx_person_idx_person_visits_person_idorder_person_id', 'person_visits', 'person_id'
);

CALL create_index_if_not_exists (
    'idx_person_visits_pizzeria_id', 'person_visits', 'pizzeria_id'
);

SELECT count(*) = 5 AS CHECK
FROM pg_indexes
WHERE
    indexname IN (
        'idx_menu_pizzeria_id', 'idx_person_order_person_id', 'idx_person_order_menu_id', 'idx_person_visits_person_id', 'idx_person_visits_pizzeria_id'
    );