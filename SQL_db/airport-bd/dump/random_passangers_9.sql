SET SESSION cte_max_recursion_depth = 1000000;
SET max_execution_time = 1000000;
SET GLOBAL cte_max_recursion_depth=10000030;
use airportdb;
create table `passengers` as
with recursive tmp(passenger_id, passenger_idx, firstname, lastname) as (
    select 1, 1, 'Волгоградия', 'Волголупиломова'
    union all
    select
        tmp.passenger_id + 1 as passenger_id,
        abs(rand() % 5) + 1 as passenger_idx,
        (select firstname from russian where passenger_id = passenger_idx) as firstname,
        (select lastname from russian where passenger_id = passenger_idx) as lastname
    from tmp
    WHERE passenger_id<1000000
)
select passenger_id, firstname, lastname from tmp;
ALTER TABLE `passengers`
ADD CONSTRAINT passenger_id_pk
PRIMARY KEY (passenger_id);
ALTER TABLE passengers MODIFY COLUMN passenger_id INT(8);
