drop table if exists benutzer;
create table benutzer(
name varchar(20),
nname varchar(20),
ID int(10)
)engine=InnoDB;


drop table if exists konto;
create table konto(
kontonummer int(8),
blz int(8),
saldo int(100),
kundennummer int(10)
)engine=InnoDB;


drop table if exists karte;
create table karte(
kontonummer int(8),
kundennummer int(10),
pin int(4), 
kartennummer int(10),
status varchar(10)
)engine=InnoDB;


drop table if exists kunde;
create table kunde(
kundennummer int(10),
ID int(10)
)engine=InnoDB;


drop table if exists onlinebkng;
create table onlinebkng(
bankingID int(10),
authcode int(5),
kundennummer int(10)
)engine=InnoDB;

