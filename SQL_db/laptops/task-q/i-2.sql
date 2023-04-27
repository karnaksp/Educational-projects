
begin transaction; 
update laptops set Company = 'Apple' where laptop_id = 1;
commit transaction;