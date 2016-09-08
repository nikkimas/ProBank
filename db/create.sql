set foreign_key_checks =0;

drop table if exists benutzer;
create table benutzer(
name varchar(20),
nname varchar(20),
ID int not null,
primary key (ID)
)engine=InnoDB;


drop table if exists konto;
create table konto(
kontonummer int not null,
blz int(8),
saldo int(100),
kundennummer int(10),
primary key (kontonummer),
foreign key (kundennummer) references kunde (kundennummer)
)engine=InnoDB;


drop table if exists karte;
create table karte(
kontonummer int(8),
kundennummer int(10),
pin int(4), 
kartennummer int not null,
status varchar(10),
primary key (kartennummer),
foreign key (kontonummer) references konto (kontonummer),
foreign key (kundennummer) references kunde (kundennummer)
)engine=InnoDB;


drop table if exists kunde;
create table kunde(
kundennummer int not null,
ID int(10),
primary key (kundennummer),
foreign key (ID) references benutzer (ID)
)engine=InnoDB;


drop table if exists onlinebkng;
create table onlinebkng(
bankingID int(10),
authcode int(5),
kundennummer int(10),
foreign key (kundennummer) references kunde (kundennummer)
)engine=InnoDB;

