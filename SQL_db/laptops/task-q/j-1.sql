set transaction isolation level repeatable read;
begin transaction; 
select * from laptops;
rollback transaction;