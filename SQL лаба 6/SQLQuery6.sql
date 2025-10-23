/*
Created: 28.05.2024
Modified: 28.05.2024
Model: Logical model2
Database: MS SQL Server 2019
*/


-- Create tables section -------------------------------------------------

-- Table E1

CREATE TABLE [E1]
(
 [Название_товара] Varchar(30) NOT NULL,
 [Описание_товара] Varchar(30) NOT NULL,
 [Стоимость_товара] Decimal(10,0) NOT NULL,
 [Сведения_о_принадлежности_товара_категории] Int NOT NULL,
 [Количество_товара_на_складе] Int NOT NULL,
 [Номер_покупателя] Varchar(30) NOT NULL
)
go

-- Create indexes for table E1

CREATE INDEX [IX_R5] ON [E1] ([Номер_покупателя])
go

-- Add keys for table E1

ALTER TABLE [E1] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([Название_товара])
go

-- Table E2

CREATE TABLE [E2]
(
 [Номер_категории] Int NOT NULL,
 [Название_категории] Varchar(30) NOT NULL,
 [Описание_категории] Varchar(30) NOT NULL,
 [Название_товара] Varchar(30) NOT NULL
)
go

-- Create indexes for table E2

CREATE INDEX [IX_R1] ON [E2] ([Название_товара])
go

-- Add keys for table E2

ALTER TABLE [E2] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([Номер_категории])
go

-- Table E3

CREATE TABLE [E3]
(
 [Фамилия] Varchar(30) NOT NULL,
 [Имя] Varchar(30) NOT NULL,
 [Отчество] Varchar(30) NOT NULL,
 [Должность] Varchar(30) NOT NULL,
 [Домашний_адрес] Varchar(30) NOT NULL,
 [Телефон] Varchar(30) NOT NULL,
 [Номер_продавца] Varchar(30) NOT NULL
)
go

-- Add keys for table E3

ALTER TABLE [E3] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([Номер_продавца])
go

-- Table E4

CREATE TABLE [E4]
(
 [Фамилия] Varchar(30) NOT NULL,
 [Имя] Varchar(30) NOT NULL,
 [Отчество] Varchar(30) NOT NULL,
 [Паспортные данные] Varchar(30) NOT NULL,
 [Домашний_адрес] Varchar(30) NOT NULL,
 [Телефон] Varchar(30) NOT NULL,
 [Номер_покупателя] Varchar(30) NOT NULL
)
go

-- Add keys for table E4

ALTER TABLE [E4] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([Номер_покупателя])
go

-- Table E5

CREATE TABLE [E5]
(
 [Дата_покупки] Date NOT NULL,
 [Перечень_купленных_товаров] Varchar(30) NOT NULL,
 [Номер_покупки] Int NOT NULL,
 [Номер_покупателя] Varchar(30) NOT NULL,
 [Номер_продавца] Varchar(30) NOT NULL
)
go

-- Create indexes for table E5

CREATE INDEX [IX_R4] ON [E5] ([Номер_покупателя])
go

CREATE INDEX [IX_R3] ON [E5] ([Номер_продавца])
go

-- Add keys for table E5

ALTER TABLE [E5] ADD CONSTRAINT [Unique_Identifier5] PRIMARY KEY ([Номер_покупки])
go

-- Table E1_E5

CREATE TABLE [E1_E5]
(
 [Название_товара] Varchar(30) NOT NULL,
 [Номер_покупки] Int NOT NULL
)
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [E2] ADD CONSTRAINT [R1] FOREIGN KEY ([Название_товара]) REFERENCES [E1] ([Название_товара]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [R4] FOREIGN KEY ([Номер_покупателя]) REFERENCES [E4] ([Номер_покупателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [R3] FOREIGN KEY ([Номер_продавца]) REFERENCES [E3] ([Номер_продавца]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E1] ADD CONSTRAINT [R5] FOREIGN KEY ([Номер_покупателя]) REFERENCES [E4] ([Номер_покупателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E1_E5] ADD CONSTRAINT [R2_E1] FOREIGN KEY ([Название_товара]) REFERENCES [E1] ([Название_товара]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E1_E5] ADD CONSTRAINT [R2_E5] FOREIGN KEY ([Номер_покупки]) REFERENCES [E5] ([Номер_покупки]) ON UPDATE NO ACTION ON DELETE NO ACTION
go


