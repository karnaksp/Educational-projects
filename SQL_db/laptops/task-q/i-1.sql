set transaction isolation level read committed ;
begin transaction; 
select * from laptops;
commit transaction;