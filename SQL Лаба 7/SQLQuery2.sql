/*
Created: 30.05.2024
Modified: 13.06.2024
Model: �������2
Database: MS SQL Server 2019
*/


-- Create tables section -------------------------------------------------

-- Table E1

CREATE TABLE [E1]
(
 [���_����������] Varchar(30) NOT NULL,
 [��������_����������] Varchar(30) NOT NULL,
 [����_���������] Date NOT NULL,
 [���_������������] Varchar(30) NOT NULL,
 [����_���_��_���������] Int NOT NULL
)
go

-- Add keys for table E1

ALTER TABLE [E1] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([���_����������])
go

-- Table E2

CREATE TABLE [E2]
(
 [���_�������] Int NOT NULL,
 [��������_�������] Varchar(30) NOT NULL,
 [�����������_�������] Varchar(30) NOT NULL,
 [����] Varchar(30) NOT NULL,
 [�������] Varchar(30) NOT NULL,
 [���_����������] Varchar(30) NOT NULL,
 [���_�������������] Int NULL
)
go

-- Create indexes for table E2

CREATE INDEX [IX_R1] ON [E2] ([���_����������])
go

CREATE INDEX [IX_R4] ON [E2] ([���_�������������])
go

-- Add keys for table E2

ALTER TABLE [E2] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([���_�������])
go

-- Table E3

CREATE TABLE [E3]
(
 [�����_������] Varchar(30) NOT NULL,
 [����_���_��_���������] Int NOT NULL,
 [���_����������] Varchar(30) NOT NULL,
 [���_�������������] Int NULL
)
go

-- Create indexes for table E3

CREATE INDEX [IX_R5] ON [E3] ([���_����������])
go

CREATE INDEX [IX_R8] ON [E3] ([���_�������������])
go

-- Add keys for table E3

ALTER TABLE [E3] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([�����_������])
go

-- Table E4

CREATE TABLE [E4]
(
 [���_�������������] Int NOT NULL,
 [�������] Varchar(30) NOT NULL,
 [���] Varchar(30) NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [�����������] Varchar(30) NOT NULL,
 [����] Decimal(10,0) NOT NULL,
 [����������_�������] Varchar(30) NOT NULL,
 [���_�������] Int NOT NULL
)
go

-- Create indexes for table E4

CREATE INDEX [IX_R2] ON [E4] ([���_�������])
go

-- Add keys for table E4

ALTER TABLE [E4] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([���_�������������])
go

-- Table E6

CREATE TABLE [E6]
(
 [����_������] Varchar(30) NOT NULL,
 [�����_����] Int NOT NULL,
 [����������] Varchar(30) NOT NULL,
 [�����_������] Varchar(30) NOT NULL,
 [�����_�����������] Int NOT NULL,
 [���_�������������] Int NOT NULL,
 [���_����������] Int NOT NULL
)
go

-- Create indexes for table E6

CREATE INDEX [IX_R11] ON [E6] ([�����_�����������])
go

-- Add keys for table E6

ALTER TABLE [E6] ADD CONSTRAINT [Unique_Identifier6] PRIMARY KEY ([����_������],[�����_����],[�����_������],[���_�������������],[���_����������])
go

-- Table E7

CREATE TABLE [E7]
(
 [���_��������] Int NOT NULL,
 [�������] Varchar(30) NOT NULL,
 [���] Varchar(30) NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [����_��������] Date NOT NULL,
 [�����] Varchar(30) NOT NULL,
 [�������] Varchar(30) NOT NULL,
 [�����_������] Varchar(30) NOT NULL
)
go

-- Create indexes for table E7

CREATE INDEX [IX_R6] ON [E7] ([�����_������])
go

-- Add keys for table E7

ALTER TABLE [E7] ADD CONSTRAINT [Unique_Identifier7] PRIMARY KEY ([���_��������])
go

-- Table E8

CREATE TABLE [E8]
(
 [���_����������] Int NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [���_��������_��_���������] Int NOT NULL
)
go

-- Add keys for table E8

ALTER TABLE [E8] ADD CONSTRAINT [Unique_Identifier8] PRIMARY KEY ([���_����������])
go

-- Table E9

CREATE TABLE [E9]
(
 [�����_�����������] Int NOT NULL,
 [��������] Varchar(30) NOT NULL,
 [���_������������] Varchar(30) NOT NULL,
 [����������_�������_����] Int NOT NULL,
 [�������_�������������_������������] Varchar(30) NOT NULL,
 [���_�������] Int NOT NULL,
 [���_�������������] Int NULL
)
go

-- Create indexes for table E9

CREATE INDEX [IX_R3] ON [E9] ([���_�������])
go

CREATE INDEX [IX_R10] ON [E9] ([���_�������������])
go

-- Add keys for table E9

ALTER TABLE [E9] ADD CONSTRAINT [Unique_Identifier9] PRIMARY KEY ([�����_�����������])
go

-- Table E5

CREATE TABLE [E5]
(
 [���������_����] Varchar(30) NOT NULL,
 [���������_������] Varchar(30) NOT NULL,
 [���_�������������] Int NOT NULL,
 [���_����������] Int NOT NULL
)
go

-- Add keys for table E5

ALTER TABLE [E5] ADD CONSTRAINT [PK_E5] PRIMARY KEY ([���_�������������],[���_����������])
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [E2] ADD CONSTRAINT [R1] FOREIGN KEY ([���_����������]) REFERENCES [E1] ([���_����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E3] ADD CONSTRAINT [R5] FOREIGN KEY ([���_����������]) REFERENCES [E1] ([���_����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E6] ADD CONSTRAINT [R7] FOREIGN KEY ([�����_������]) REFERENCES [E3] ([�����_������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E3] ADD CONSTRAINT [R8] FOREIGN KEY ([���_�������������]) REFERENCES [E4] ([���_�������������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E6] ADD CONSTRAINT [R11] FOREIGN KEY ([�����_�����������]) REFERENCES [E9] ([�����_�����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E7] ADD CONSTRAINT [R6] FOREIGN KEY ([�����_������]) REFERENCES [E3] ([�����_������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E4] ADD CONSTRAINT [R2] FOREIGN KEY ([���_�������]) REFERENCES [E2] ([���_�������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E2] ADD CONSTRAINT [R4] FOREIGN KEY ([���_�������������]) REFERENCES [E4] ([���_�������������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E9] ADD CONSTRAINT [R3] FOREIGN KEY ([���_�������]) REFERENCES [E2] ([���_�������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E9] ADD CONSTRAINT [R10] FOREIGN KEY ([���_�������������]) REFERENCES [E4] ([���_�������������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [��������] FOREIGN KEY ([���_�������������]) REFERENCES [E4] ([���_�������������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [��������������] FOREIGN KEY ([���_����������]) REFERENCES [E8] ([���_����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E6] ADD CONSTRAINT [���������������] FOREIGN KEY ([���_�������������], [���_����������]) REFERENCES [E5] ([���_�������������], [���_����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



-------------------------------------------------
-- ������� -- ������� 9
-------------------------------------------------

--1. ������� ����������, �� ������� ���������� ����� ������ �������� ����� ����� �� ���� �����������.
Select []
From E1 as ���������
--2. ������� ���������� � ���, ��������� �������� ����� �������� �������������, � ������� ������ ���� ��������� � ��������.
--3. ������� ���������� ��� ���� ��������������, ������� ����� ����������, ������� ���� ����� �������� � ����������.
--4. ������� �����������, � ������� ������� ����� �������������, ���������� ���������� � ���� �����������.
--5. ��� ������ ������ ��������� ���������� �����������, � ������� ������ �� ���� �� ����������.
--6. ��������� ������� ���������� ���������, ����������� � ������� ������������� �� ���� ������.
--7. ������� ���������� � ���, ����� � ����� �������� ������������� ����� � �������, � ������� �������� ����������.