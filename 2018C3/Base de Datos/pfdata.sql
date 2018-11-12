INSERT INTO tblCliente VALUES
	('Alex',  'Jardines Del Sol, Zapopan' , '696017008','Jehielrrero@gmail.com'),
	('Bernie',  'Av. General Ramon Corona 5214, Nuevo México, Zapopan' , '723974506','IsidreUrbinaValle@gmail.com'),
	('Charl',   'Av Quintas del Bosque 298, Bosques de San Isidro, Zapopan' , '689268214','NoamBritores@gmail.com'),
	('David',   'Paseo San Raymundo, Valle Real, Zapopan' , '774860026','RaidisorioSepulveda@gmail.com'),
	('Enrique', 'Paseo Vitana 965, Altavista Residencial, Zapopan' , '742252341','AdelfoOlivasSolis@gmail.com'),
	('Fernando','Av Juan Gil Preciado No 6640, Nuevo México, Zapopan' , '607226821','CarranzaTrujillo@gmail.com'),
	('Gerardo', 'Av de las Palmas 200, Villa Coral, Zapopan' , '785747996','ObedMirelgadillo@gmail.com'), 
	('Hector',  'Chichen itza, Jardines Del Sol, Zapopan' , '3312345678','HectorHH@gmail.com'),
	('Aria',    'Av. Guadalajara #4252, Fraccionamiento Valle Imperial, Zapopan' , '3312345679','AriaGiselle@gmail.com'),
	('Javier', 'Ramon Corona 1500 - Valle Real, Zapopan' , '3312345670','JaviL1291@gmail.com');

INSERT INTO tblEmpleado VALUES
	( 'Admin',    'Abel Ayala 87, Seattle, Zapopan' , '3312345671', 'MELM8305281H0', 'UserAdmin'), 
	( 'Bruno',    'Av Federalistas, Fraccionamiento La Cima, Zapopan ' , '3312345672', 'MELM8315281H0', 'LittlePet1'), 
	( 'Carmen',   'Puerto Isabel 111, Miramar, Zapopan' , '3312125673', 'MELM8325281H0', NULL), 
	( 'Daniel',   'Circuito Plumbago, Puertas Del Tule, Zapopan' , '3312303674', 'MELM8335281H0', NULL), 
	( 'Estela',   'Camino a Bosque de San Isidro 2470, El Centinela, Zapopan' , '3317345675', 'MELM8345281H0', NULL), 
	( 'Fabiola',  'Valle Real, Zapopan' , '3312345676', 'MELM8355281H0', NULL), 
	( 'Gabriela', 'Coto Cataluña 106, Puerta de Hierro, Zapopan' , '3312345677', 'MELM8365281H0', NULL), 
	( 'Helio',    'Palomas 70, Lomas Del Batan, Zapopan' , '3312345678', 'MELM8375281H0', NULL), 
	( 'Ismael',   'Av Federalitas no 2121, Fraccionamiento La Cima, Zapopan' , '3312345679', 'MELM8385281H0', NULL), 
	( 'Jalapa',   'Calle Cuitlahuac 4196, Jardines Del Sol, Zapopan' , '3312345670', 'MELM8395281H0', NULL);
	
INSERT INTO tblMascota VALUES
	(1,  9 , 'ARUALAIS' , 'PERRO' , 'PASTOR ALEMAN' , 'CAFE' , 15.2, 'MACHO'  , convert(datetime, 01-01-2014)),
	(1,  10, 'BERULAIS' , 'PERRO' , 'PASTOR ALEMAN' , 'NEGRO', 10.0, 'MACHO'  , convert(datetime, 01-01-2015)),
	(8,  7 , 'CARULAIS' , 'PERRO' , 'PASTOR ALEMAN' , 'NEGRO', 8.0 , 'MACHO'  , convert(datetime, 01-01-2012)),
	(2,  4 , 'DAVULAIS' , 'PERRO' , 'PASTOR ALEMAN' , 'CAFE' , 7.5 , 'MACHO'  , convert(datetime, 01-01-2013)),
	(7,  5 , 'FIRULAIS' , 'PERRO' , 'CALLEJERO' , 'BLANCO'   , 9.8 , 'MACHO'  , convert(datetime, 01-01-2017)),
	(2,  3 , 'GIRULAIS' , 'GATO'  , 'SPHYNX'    , 'GRIS'     , 3.2 , 'HEMBRA' , convert(datetime, 01-01-2016)),
	(9,  2 , 'HERULAIS' , 'GATO'  , 'SPHYNX'    , 'BLANCO'   , 4.0 , 'HEMBRA' , convert(datetime, 01-01-2010)),
	(4,  3 , 'IRULAIS'  , 'GATO'  , 'SPHYNX'    , 'NEGRO'    , 2.1 , 'MACHO'  , convert(datetime, 01-01-2013)),
	(5,  6 , 'JIRUAIS'  , 'GATO'  , 'CALLEJERO' , 'CAFE'     , 3.4 , 'MACHO'  , convert(datetime, 01-01-2015)),
	(6,  4 , 'KASSAB'   , 'GATO'  , 'CALLEJERO' , 'BLANCO'   , 2.7 , 'HEMBRA' , convert(datetime, 01-01-2018));

 INSERT INTO tblCentroEstudio VALUES
	 ('Hospital Veterinario Guadalajara' , 'Paseo de la Luna 500, Fraccionamiento Solares, Zapopan' , '3398765412'), 
	 ('Clinica Veterinaria Senior Dog´s' , 'H. Colegio Militar 4352, El Fortín, Zapopan' , '3398365413'), 
	 ('Animal´s Medicos Veterinarios' , 'Paseo San Victor, Valle Real, Zapopan' , '3398765414'), 
	 ('Clinica Veterinaria Copernico' , 'Mariano Otero, Los Robles, Zapopan' , '3398765415'), 
	 ('Hospital Veterinario de Pequeñas Especies' , 'Av Vallarta 2701, San Juan de Ocotan, Zapopan' , '3398895416'),
	 ('Mundo Canino' , 'Paseo de las Margaritas,Fraccionamiento Bugambilias, Zapopan' , '3398355417'),
	 ('Veteronaria San Diego' , 'Villa Verona, Virreyes Residencial, Zapopan' , '3398765418'), 
	 ('Centro Canino Mora' , 'San Juan Bosco #333, Fraccionamiento Bosques de San Gonzalo, Zapopan' , '3398755719'),
	 ('Veterinaria Gallardo' , 'Paseo del Carnero 4116 Bugambilias, Zapopan, Jalisco' , '3398761211'), 
	 ('Veterinaria del Centro' , 'Tajin 5730, Pinar de La Calma, Zapopan' , '3398760010');
 
INSERT INTO tblAnalisis VALUES
	('Sangre' ,NULL, 1, 100 ), 
	('Orina' , NULL, 2, 200), 
	('Antitrombina III' , NULL,1, 200),  
	('Ferritina' , NULL, 2, 400), 
	('Hemograma' , NULL, 1, 500), 
	('Glucosa' , NULL, 2, 600), 
	('Hemoglobina', NULL, 2,700), 
	('ACTH' , NULL, 1, 800), 
	('Insulina' , NULL, 2, 900), 
	('TSH Canina' , NULL, 1, 1000);

INSERT INTO tblProducto VALUES 
	('Jaula' , 10 , 500), 
	('Correa' , 20 , 450), 
	('Comida para Gato' , 15 , 400), 
	('Gabardina' , 30 , 350), 
	('Antipulgas' , 25 , 300), 
	('Cepillo Dental' , 40 , 250), 
	('Pasta Dental' , 35 , 200), 
	('Plato de Acero' , 50 , 150), 
	('Galletas' , 45 , 100), 
	('Hueso Madera' , 60 , 50 ); 

INSERT INTO tblProveedor VALUES
	('Ivett SA de CV' , 'Av Santa Margarita 4050, Fraccionamiento Jardín Real, Zapopan' , '3318065412' , 'NWM9709244W4'), 
	('Petuky' , 'Paseo San Arturo Oriente 100, Valle Real, Zapopan' , '3310765013' , 'ODM950324U2A'), 
	('Pet Mark' , 'Paseo del Vallado 3190 - Colinas de San Javier, Zapopan' , '3314205414' , 'ROOA6411012F'), 
	('Disnapet' , 'Av D 460 , Seattle, Zapopan' , '3318765415' , 'MSI060522614'), 
	('Petsy' , 'Av Avila Camacho, Jacarandas, Zapopan' , '3311260416' , 'APV980724JR7'), 
	('Todo para tu Mascota' , 'Valle de Ameca 2777, Parque Real, Zapopan' , '3318765417' , 'CLI010507BQA'), 
	('Petgo' , 'Av. Periferico Pte. Manuel Gómez Morín 2490, Las Fuentes, Zapopan' , '3318069418' , 'PDPR830516JT'), 
	('Mascota Sana' , 'Federico Chopin 5080, La Estancia, Zapopan' , '3318765419' , 'EDG010404AP7'), 
	('Tienda Animal' , 'Av. Circunvalación Oriente 1130 Int 9, Ciudad Granja, Zapopan' , '3318765811' , 'FOMV120728GK'), 
	('Vet Mark' , 'Jardin Del Palacio #18, Fraccionamiento Jardín Real, Zapopan' , '3318760010' , 'OQJ5405189B2'); 

INSERT INTO tblAnalisisCentro VALUES
	(4,1),
	(5,1),
	(6,1),
	(8,3),
	(4,10);

INSERT INTO tblAnalisisEmpleado VALUES
	(1,5),
	(1,4),
	(1,3),
	(2,5);

INSERT INTO tblProductoProveedor VALUES
	(2,4),
	(2,5),
	(2,6),
	(3,6),
	(3,9),
	(1,2),
	(1,3),
	(9,10);

INSERT INTO tblCompra VALUES
	(3),
	(7);

INSERT INTO tblCompraDetalle VALUES
	(1,7),
	(1,5),
	(1,3),
	(2,5);