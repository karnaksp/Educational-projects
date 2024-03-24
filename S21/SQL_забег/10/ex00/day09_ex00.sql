-- Active: 1706346565365@@127.0.0.1@5432@pizza
CREATE TABLE "person_audit" (
    "created" TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT CURRENT_TIMESTAMP, "type_event" CHAR(1) CONSTRAINT "ch_type_event" CHECK (
        "type_event" IN ('I', 'D', 'U')
    ) NOT NULL DEFAULT 'I', "row_id" bigint NOT NULL, "name" varchar, "age" integer, "gender" varchar, "address" varchar
);

CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit
() RETURNS TRIGGER AS 
$$
BEGIN
	INSERT INTO
	    "person_audit" (
	        "row_id", "name", "age", "gender", "address"
	    )
	VALUES (
	        NEW."id", NEW."name", NEW."age", NEW."gender", NEW."address"
	    );
	RETURN NEW;
END;
$$
LANGUAGE
PLPGSQL; 

CREATE TRIGGER trg_person_insert_audit
AFTER INSERT ON "person" FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_insert_audit ();

INSERT INTO
    "person" (
        "id", "name", "age", "gender", "address"
    )
VALUES (
        10, 'Damir', 22, 'male', 'Irkutsk'
    );

SELECT * FROM "person";

SELECT * FROM "person_audit";