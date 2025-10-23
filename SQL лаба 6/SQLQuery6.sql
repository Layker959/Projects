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
 [��������_������] Varchar(30) NOT NULL,
 [��������_������] Varchar(30) NOT NULL,
 [���������_������] Decimal(10,0) NOT NULL,
 [��������_�_��������������_������_���������] Int NOT NULL,
 [����������_������_��_������] Int NOT NULL,
 [�����_����������] Varchar(30) NOT NULL
)
go

-- Create indexes for table E1

CREATE INDEX [IX_R5] ON [E1] ([�����_����������])
go

-- Add keys for table E1

ALTER TABLE [E1] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([��������_������])
go

-- Table E2

CREATE TABLE [E2]
(
 [�����_���������] Int NOT NULL,
 [��������_���������] Varchar(30) NOT NULL,
 [��������_���������] Varchar(30) NOT NULL,
 [��������_������] Varchar(30) NOT NULL
)
go

-- Create indexes for table E2

CREATE INDEX [IX_R1] ON [E2] ([��������_������])
go

-- Add keys for table E2

ALTER TABLE [E2] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([�����_���������])
go

-- Table E3

CREATE TABLE [E3]
(
 [�������] Varchar(30) NOT NULL,
 [���] Varchar(30) NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [���������] Varchar(30) NOT NULL,
 [��������_�����] Varchar(30) NOT NULL,
 [�������] Varchar(30) NOT NULL,
 [�����_��������] Varchar(30) NOT NULL
)
go

-- Add keys for table E3

ALTER TABLE [E3] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([�����_��������])
go

-- Table E4

CREATE TABLE [E4]
(
 [�������] Varchar(30) NOT NULL,
 [���] Varchar(30) NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [���������� ������] Varchar(30) NOT NULL,
 [��������_�����] Varchar(30) NOT NULL,
 [�������] Varchar(30) NOT NULL,
 [�����_����������] Varchar(30) NOT NULL
)
go

-- Add keys for table E4

ALTER TABLE [E4] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([�����_����������])
go

-- Table E5

CREATE TABLE [E5]
(
 [����_�������] Date NOT NULL,
 [��������_���������_�������] Varchar(30) NOT NULL,
 [�����_�������] Int NOT NULL,
 [�����_����������] Varchar(30) NOT NULL,
 [�����_��������] Varchar(30) NOT NULL
)
go

-- Create indexes for table E5

CREATE INDEX [IX_R4] ON [E5] ([�����_����������])
go

CREATE INDEX [IX_R3] ON [E5] ([�����_��������])
go

-- Add keys for table E5

ALTER TABLE [E5] ADD CONSTRAINT [Unique_Identifier5] PRIMARY KEY ([�����_�������])
go

-- Table E1_E5

CREATE TABLE [E1_E5]
(
 [��������_������] Varchar(30) NOT NULL,
 [�����_�������] Int NOT NULL
)
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [E2] ADD CONSTRAINT [R1] FOREIGN KEY ([��������_������]) REFERENCES [E1] ([��������_������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [R4] FOREIGN KEY ([�����_����������]) REFERENCES [E4] ([�����_����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [R3] FOREIGN KEY ([�����_��������]) REFERENCES [E3] ([�����_��������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E1] ADD CONSTRAINT [R5] FOREIGN KEY ([�����_����������]) REFERENCES [E4] ([�����_����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E1_E5] ADD CONSTRAINT [R2_E1] FOREIGN KEY ([��������_������]) REFERENCES [E1] ([��������_������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E1_E5] ADD CONSTRAINT [R2_E5] FOREIGN KEY ([�����_�������]) REFERENCES [E5] ([�����_�������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go


