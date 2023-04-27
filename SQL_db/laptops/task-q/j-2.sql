set transaction isolation level repeatable read;
begin transaction; 
update laptops set Company = 'Apple' where laptop_id = 1;
rollback transaction;