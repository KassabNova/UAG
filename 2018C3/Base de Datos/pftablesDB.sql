
-- Tablas Principales

CREATE TABLE tblCliente (
	IdCliente INT NOT NULL IDENTITY PRIMARY KEY,
	Nombre VARCHAR(30) NOT NULL,
	Domicilio VARCHAR(100),
	Teléfono VARCHAR(12) NOT NULL,
	Correo VARCHAR(255),
);

CREATE TABLE tblEmpleado (
	IdEmpleado INT NOT NULL IDENTITY PRIMARY KEY,
	Nombre VARCHAR(30) NOT NULL,
	Domicilio VARCHAR(100),
	Teléfono VARCHAR(12),
	RFC VARCHAR(30)NOT NULL,
	Contrasenia VARCHAR(30)
);


CREATE TABLE tblMascota (
	IdMascota INT NOT NULL IDENTITY PRIMARY KEY,
	IdCliente INT NOT NULL,
	IdEmpleado INT,  
	Nombre VARCHAR(20) NOT NULL,
	Especie VARCHAR(15),
	Raza VARCHAR(20),
	Color VARCHAR(10),
	Peso FLOAT,
	Sexo VARCHAR(10),
	FNacimiento DATE,
	CONSTRAINT FK_IdEmpleado_tblMascota FOREIGN KEY (IdEmpleado) REFERENCES tblEmpleado(IdEmpleado) ON DELETE SET NULL ON UPDATE CASCADE,
	CONSTRAINT FK_IdCliente_tblMascota FOREIGN KEY (IdCliente) REFERENCES tblCliente(IdCliente) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE tblCentroEstudio (
	IdCentro INT NOT NULL IDENTITY PRIMARY KEY,
	Nombre VARCHAR(50) NOT NULL,
	Domicilio VARCHAR(100),
	Telefono VARCHAR(12)
);
CREATE TABLE tblAnalisis (
	IdAnalisis INT NOT NULL IDENTITY PRIMARY KEY,
	Nombre VARCHAR(30),
	Descripcion VARCHAR(50),
	DiaEspera INTEGER, 
	Precio MONEY NOT NULL,
);

-- Tabla de Normalizacion entre tblAnalisis y tblCentro Estudio
	CREATE TABLE tblAnalisisCentro (
		IdAnalisisCentro INT NOT NULL IDENTITY PRIMARY KEY,
		IdAnalisis INT NOT NULL,
		IdCentro INT NOT NULL,
		CONSTRAINT FK_IdAnalisis_tblAnalisisCentro FOREIGN KEY (IdAnalisis) REFERENCES tblAnalisis(IdAnalisis),
		CONSTRAINT FK_IdCentro_tblAnalisisCentro FOREIGN KEY (IdCentro) REFERENCES tblCentroEstudio(IdCentro)
		ON DELETE CASCADE ON UPDATE CASCADE 
	);

-- Tabla de Normalizacion entre tblAnalisis y tblEmpleado
	CREATE TABLE tblAnalisisEmpleado (
		IdAnalisisEmpleado INT NOT NULL IDENTITY PRIMARY KEY, 
		IdAnalisis INT NOT NULL,
		IdEmpleado INT NOT NULL,
		CONSTRAINT FK_IdAnalisis_tblAnalisisEmpleado FOREIGN KEY (IdAnalisis) REFERENCES tblAnalisis(IdAnalisis),
		CONSTRAINT FK_IdEmpleado_tblAnalisisEmpleado FOREIGN KEY (IdEmpleado) REFERENCES tblEmpleado(IdEmpleado)
		ON DELETE CASCADE ON UPDATE CASCADE 
	);

CREATE TABLE tblProducto (
	IdProducto INT NOT NULL IDENTITY PRIMARY KEY,
	Nombre VARCHAR(30) NOT NULL,
	Cantidad INT NOT NULL,
	Precio MONEY NOT NULL,
);

CREATE TABLE tblProveedor (
	IdProveedor INT NOT NULL  IDENTITY PRIMARY KEY,
	Nombre VARCHAR(50)NOT NULL,
	Domicilio VARCHAR(100),
	Telefono VARCHAR(12) NOT NULL,
	RFC VARCHAR(30) NOT NULL
);

-- Tabla de Normalizacion entre tblProducto y tblProveedor
	CREATE TABLE tblProductoProveedor (
	IdProductoProveedor INT IDENTITY PRIMARY KEY, 
	IdProducto INT NOT NULL,
	IdProveedor INT NOT NULL,
	CONSTRAINT FK_IdProducto_tblProductoProveedor FOREIGN KEY (IdProducto) REFERENCES tblProducto(IdProducto),
	CONSTRAINT FK_Proveedor_tblPorductoProveedor FOREIGN KEY (IdProveedor) REFERENCES tblProveedor(IdProveedor)
	ON DELETE CASCADE ON UPDATE CASCADE 
);

-- Tablas de Normalizacion entre tblCliente y tblProducto 
		CREATE TABLE tblCompra (
		IdCompra INT NOT NULL IDENTITY PRIMARY KEY,
		IdCliente INT NOT NULL,
		CONSTRAINT FK_IdCliente_tblCompra FOREIGN KEY (IdCliente) REFERENCES tblCliente(IdCliente)
		ON DELETE CASCADE ON UPDATE CASCADE 
	);

		CREATE TABLE tblCompraDetalle (
		IdCompra INT NOT NULL, 
		IdProducto INT NOT NULL,
		CONSTRAINT FK_IdCompra_tblCompraDetalle FOREIGN KEY (IdCompra) REFERENCES tblCompra(IdCompra),
		CONSTRAINT FK_IdProducto_tblCompraDetalle FOREIGN KEY (IdProducto) REFERENCES tblProducto(IdProducto)
		ON DELETE CASCADE ON UPDATE CASCADE 
	);

