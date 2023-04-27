set transaction isolation level serializable;
begin transaction; 
select * from laptops;
commit transaction;