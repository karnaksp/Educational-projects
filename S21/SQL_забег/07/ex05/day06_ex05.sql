COMMENT ON TABLE person_discounts IS 'Таблица, содержащая информацию о персональных скидках для людей и пиццерий';

COMMENT ON COLUMN person_discounts.id IS 'Первичный ключ для таблицы person_discounts';

COMMENT ON COLUMN person_discounts.person_id IS 'Внешний ключ, ссылается на столбец id в таблице person';

COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Внешний ключ, ссылается на столбец id в таблице pizzeria';

COMMENT ON COLUMN person_discounts.discount IS 'Значение скидки в процентах, в пределах от 0 до 100';