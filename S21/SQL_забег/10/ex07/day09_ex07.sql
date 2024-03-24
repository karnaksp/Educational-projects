CREATE OR REPLACE FUNCTION 
    func_minimum(VARIADIC arr numeric [])
RETURNS numeric
LANGUAGE SQL
AS $$
  SELECT MIN(elements) FROM unnest($1) elements
$$;


SELECT func_minimum(
    VARIADIC arr => ARRAY[
        10.0, -1.0, 5.0, 4.4
    ]
);