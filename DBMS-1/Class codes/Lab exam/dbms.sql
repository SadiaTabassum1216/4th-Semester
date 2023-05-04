drop table sailors;
drop table reserve;
drop table boats;

create table sailors(sid number,sname varchar(20),rating number, age number);
create table reserve(sid number, bid number,day varchar(20));
create table boats(bid number, bname varchar(20),color varchar(20));

insert into sailors values(22,'Dustin',7,45.0);
insert into sailors values(29,'Brutus',1,33.0);
insert into sailors values(31,'Lubber',8,55.5);
insert into sailors values(32,'Andy',8,25.5);
insert into sailors values(58,'Rusty',10,35.0);
insert into sailors values(64,'Horatio',7,35.0);
insert into sailors values(71,'Zorba',10,16.0);
insert into sailors values(71,'Horatio',9,35.0);
insert into sailors values(85,'Art',3,25.5);
insert into sailors values(95,'Bob',3,63.5);


insert into reserve values(22,101,'10/10/98');
insert into reserve values(22,102,'10/10/98');
insert into reserve values(22,103,'10/8/98');
insert into reserve values(22,104,'10/7/98');
insert into reserve values(31,102,'11/10/98');
insert into reserve values(31,103,'11/6/98');
insert into reserve values(31,104,'11/12/98');
insert into reserve values(64,101,'9/5/98');
insert into reserve values(64,102,'9/8/98');
insert into reserve values(74,103,'9/8/98');

insert into boats values(101,'Interlake','blue');
insert into boats values(102,'Interlake','red');
insert into boats values(103,'Clipper','green');
insert into boats values(104,'Marine','red');