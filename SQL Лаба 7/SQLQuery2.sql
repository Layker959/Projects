/*
Created: 30.05.2024
Modified: 13.06.2024
Model: Колледж2
Database: MS SQL Server 2019
*/


-- Create tables section -------------------------------------------------

-- Table E1

CREATE TABLE [E1]
(
 [Код_факультета] Varchar(30) NOT NULL,
 [Название_факультета] Varchar(30) NOT NULL,
 [Дата_основания] Date NOT NULL,
 [Род_деятельности] Varchar(30) NOT NULL,
 [Макс_кол_во_студентов] Int NOT NULL
)
go

-- Add keys for table E1

ALTER TABLE [E1] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([Код_факультета])
go

-- Table E2

CREATE TABLE [E2]
(
 [Код_кафедры] Int NOT NULL,
 [Название_кафедры] Varchar(30) NOT NULL,
 [Выпускающая_кафедра] Varchar(30) NOT NULL,
 [Сайт] Varchar(30) NOT NULL,
 [Телефон] Varchar(30) NOT NULL,
 [Код_факультета] Varchar(30) NOT NULL,
 [Код_преподавателя] Int NULL
)
go

-- Create indexes for table E2

CREATE INDEX [IX_R1] ON [E2] ([Код_факультета])
go

CREATE INDEX [IX_R4] ON [E2] ([Код_преподавателя])
go

-- Add keys for table E2

ALTER TABLE [E2] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([Код_кафедры])
go

-- Table E3

CREATE TABLE [E3]
(
 [Номер_группы] Varchar(30) NOT NULL,
 [Макс_кол_во_студентов] Int NOT NULL,
 [Код_факультета] Varchar(30) NOT NULL,
 [Код_преподавателя] Int NULL
)
go

-- Create indexes for table E3

CREATE INDEX [IX_R5] ON [E3] ([Код_факультета])
go

CREATE INDEX [IX_R8] ON [E3] ([Код_преподавателя])
go

-- Add keys for table E3

ALTER TABLE [E3] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([Номер_группы])
go

-- Table E4

CREATE TABLE [E4]
(
 [Код_преподавателя] Int NOT NULL,
 [Фамилия] Varchar(30) NOT NULL,
 [Имя] Varchar(30) NOT NULL,
 [Отчество] Varchar(30) NOT NULL,
 [Образование] Varchar(30) NOT NULL,
 [Стаж] Decimal(10,0) NOT NULL,
 [Контактный_телефон] Varchar(30) NOT NULL,
 [Код_кафедры] Int NOT NULL
)
go

-- Create indexes for table E4

CREATE INDEX [IX_R2] ON [E4] ([Код_кафедры])
go

-- Add keys for table E4

ALTER TABLE [E4] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([Код_преподавателя])
go

-- Table E6

CREATE TABLE [E6]
(
 [День_недели] Varchar(30) NOT NULL,
 [Номер_пары] Int NOT NULL,
 [Примечание] Varchar(30) NOT NULL,
 [Номер_группы] Varchar(30) NOT NULL,
 [Номер_лаборатории] Int NOT NULL,
 [Код_преподавателя] Int NOT NULL,
 [Код_дисциплины] Int NOT NULL
)
go

-- Create indexes for table E6

CREATE INDEX [IX_R11] ON [E6] ([Номер_лаборатории])
go

-- Add keys for table E6

ALTER TABLE [E6] ADD CONSTRAINT [Unique_Identifier6] PRIMARY KEY ([День_недели],[Номер_пары],[Номер_группы],[Код_преподавателя],[Код_дисциплины])
go

-- Table E7

CREATE TABLE [E7]
(
 [Код_студента] Int NOT NULL,
 [Фамилия] Varchar(30) NOT NULL,
 [Имя] Varchar(30) NOT NULL,
 [Отчество] Varchar(30) NOT NULL,
 [Дата_рождения] Date NOT NULL,
 [Адрес] Varchar(30) NOT NULL,
 [Телефон] Varchar(30) NOT NULL,
 [Номер_группы] Varchar(30) NOT NULL
)
go

-- Create indexes for table E7

CREATE INDEX [IX_R6] ON [E7] ([Номер_группы])
go

-- Add keys for table E7

ALTER TABLE [E7] ADD CONSTRAINT [Unique_Identifier7] PRIMARY KEY ([Код_студента])
go

-- Table E8

CREATE TABLE [E8]
(
 [Код_дисциплины] Int NOT NULL,
 [Название] Varchar(30) NOT NULL,
 [Описание] Varchar(30) NOT NULL,
 [Год_введения_по_стандарту] Int NOT NULL
)
go

-- Add keys for table E8

ALTER TABLE [E8] ADD CONSTRAINT [Unique_Identifier8] PRIMARY KEY ([Код_дисциплины])
go

-- Table E9

CREATE TABLE [E9]
(
 [Номер_лаборатории] Int NOT NULL,
 [Название] Varchar(30) NOT NULL,
 [Род_деятельности] Varchar(30) NOT NULL,
 [Количество_рабочих_мест] Int NOT NULL,
 [Наличие_проекционного_оборудования] Varchar(30) NOT NULL,
 [Код_кафедры] Int NOT NULL,
 [Код_преподавателя] Int NULL
)
go

-- Create indexes for table E9

CREATE INDEX [IX_R3] ON [E9] ([Код_кафедры])
go

CREATE INDEX [IX_R10] ON [E9] ([Код_преподавателя])
go

-- Add keys for table E9

ALTER TABLE [E9] ADD CONSTRAINT [Unique_Identifier9] PRIMARY KEY ([Номер_лаборатории])
go

-- Table E5

CREATE TABLE [E5]
(
 [Стоимость_часа] Varchar(30) NOT NULL,
 [Почасовая_оплата] Varchar(30) NOT NULL,
 [Код_преподавателя] Int NOT NULL,
 [Код_дисциплины] Int NOT NULL
)
go

-- Add keys for table E5

ALTER TABLE [E5] ADD CONSTRAINT [PK_E5] PRIMARY KEY ([Код_преподавателя],[Код_дисциплины])
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [E2] ADD CONSTRAINT [R1] FOREIGN KEY ([Код_факультета]) REFERENCES [E1] ([Код_факультета]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E3] ADD CONSTRAINT [R5] FOREIGN KEY ([Код_факультета]) REFERENCES [E1] ([Код_факультета]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E6] ADD CONSTRAINT [R7] FOREIGN KEY ([Номер_группы]) REFERENCES [E3] ([Номер_группы]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E3] ADD CONSTRAINT [R8] FOREIGN KEY ([Код_преподавателя]) REFERENCES [E4] ([Код_преподавателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E6] ADD CONSTRAINT [R11] FOREIGN KEY ([Номер_лаборатории]) REFERENCES [E9] ([Номер_лаборатории]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E7] ADD CONSTRAINT [R6] FOREIGN KEY ([Номер_группы]) REFERENCES [E3] ([Номер_группы]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E4] ADD CONSTRAINT [R2] FOREIGN KEY ([Код_кафедры]) REFERENCES [E2] ([Код_кафедры]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E2] ADD CONSTRAINT [R4] FOREIGN KEY ([Код_преподавателя]) REFERENCES [E4] ([Код_преподавателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E9] ADD CONSTRAINT [R3] FOREIGN KEY ([Код_кафедры]) REFERENCES [E2] ([Код_кафедры]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E9] ADD CONSTRAINT [R10] FOREIGN KEY ([Код_преподавателя]) REFERENCES [E4] ([Код_преподавателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [Получает] FOREIGN KEY ([Код_преподавателя]) REFERENCES [E4] ([Код_преподавателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E5] ADD CONSTRAINT [Распределяется] FOREIGN KEY ([Код_дисциплины]) REFERENCES [E8] ([Код_дисциплины]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [E6] ADD CONSTRAINT [Устанавливается] FOREIGN KEY ([Код_преподавателя], [Код_дисциплины]) REFERENCES [E5] ([Код_преподавателя], [Код_дисциплины]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



-------------------------------------------------
-- Запросы -- Вариант 9
-------------------------------------------------

--1. Вывести факультеты, на которых количество групп больше среднего числа групп по всем факультетам.
Select []
From E1 as Факультет
--2. Вывести информацию о том, куратором скольких групп являются преподаватели, у которых меньше трех дисциплин в нагрузке.
--3. Вывести информацию обо всех преподавателях, которые ведут дисциплины, которые чаще всего ставятся в расписание.
--4. Вывести лаборатории, в которых занятия ведет преподаватель, являющийся заведующим в этой лаборатории.
--5. Для каждой группы посчитать количество лабораторий, в которых группа ни разу не занималась.
--6. Посчитать среднее количество студентов, обучающихся у каждого преподавателя по дням недели.
--7. Вывести информацию о том, когда и какие предметы преподаватели ведут в группах, в которых являются кураторами.