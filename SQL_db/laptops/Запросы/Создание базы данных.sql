-- -----------------------------------------------------
-- Table order - заказы
-- -----------------------------------------------------
CREATE TABLE orders(
  order_id INT NOT NULL IDENTITY(1,1),
  order_date VARCHAR(255) NOT NULL,
  PRIMARY KEY (order_id)
);

CREATE UNIQUE INDEX id_order_UNIQUE ON orders(order_id);

-- -----------------------------------------------------
-- Table suppliers - поставщики
-- -----------------------------------------------------
CREATE TABLE suppliers (
  suppliers_id INT NOT NULL IDENTITY(1,1),
  suppliers_name VARCHAR(50) NOT NULL,
  PRIMARY KEY (suppliers_id)
);

CREATE UNIQUE INDEX id_suppliers_UNIQUE ON suppliers(suppliers_id);

-- -----------------------------------------------------
-- Table supples - поставки
-- -----------------------------------------------------
CREATE TABLE supples (
  supple_id INT NOT NULL IDENTITY(1,1),
  id_suppliers INT NOT NULL,
  supple_date DATE NOT NULL,
  id_order INT NOT NULL,
  PRIMARY KEY (supple_id),
  CONSTRAINT fk_supples_suppliers
    FOREIGN KEY (id_suppliers)
    REFERENCES suppliers(suppliers_id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_supple_order
    FOREIGN KEY (id_order)
    REFERENCES orders(order_id)
    ON UPDATE CASCADE
);

CREATE INDEX fk_supples_suppliers ON supples(id_suppliers);
CREATE INDEX fk_supple_order ON supples(id_order);
CREATE UNIQUE INDEX id_supple_UNIQUE ON supples(supple_id);

-- -----------------------------------------------------
-- Table constructors - сборки
-- -----------------------------------------------------
CREATE TABLE constructors (
  constructor_id INT NOT NULL IDENTITY(1,1),
  id_supple INT NOT NULL,
  supple_date DATE NOT NULL,
  constructor_date DATE NOT NULL,
  constructor_name VARCHAR(50) NOT NULL,
  PRIMARY KEY (constructor_id),
  CONSTRAINT fk_constructor_supples
    FOREIGN KEY (id_supple)
    REFERENCES supples(supple_id)
    ON UPDATE CASCADE
);

CREATE UNIQUE INDEX id_constructor_UNIQUE ON constructors(constructor_id);
CREATE INDEX fk_constructor_supples ON constructors(id_supple);
-- -----------------------------------------------------
-- Table shops - магазины
-- -----------------------------------------------------
CREATE TABLE shops (
  shop_id INT NOT NULL IDENTITY(1,1),
  chop_name VARCHAR(25) NOT NULL,
  PRIMARY KEY (shop_id)
);

CREATE UNIQUE INDEX id_shop_UNIQUE ON shops(shop_id);

-- -----------------------------------------------------
-- Table laptop - компьютеры в магазине
-- -----------------------------------------------------

CREATE TABLE laptops (
  laptop_id INT NOT NULL IDENTITY(1,1),
  Company VARCHAR(9) NOT NULL,
  Product VARCHAR(45) NOT NULL,
  TypeName VARCHAR(18) NOT NULL,
  Inches DECIMAL(3,1) NOT NULL,
  ScreenResolution VARCHAR(45) NOT NULL,
  Cpu VARCHAR(37) NOT NULL,
  Ram VARCHAR(4) NOT NULL,
  Memory VARCHAR(29) NOT NULL,
  Gpu VARCHAR(30) NOT NULL,
  OpSys VARCHAR(12) NOT NULL,
  Weight_kg DECIMAL(4,3) NOT NULL,
  Price_euros DECIMAL(6,2) NOT NULL,
  id_shop INT NOT NULL,
  id_constructors INT NOT NULL,
  PRIMARY KEY (laptop_id),
  CONSTRAINT fk_laptop_shop
    FOREIGN KEY (id_shop)
    REFERENCES shops (shop_id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_laptop_constructors
    FOREIGN KEY (id_constructors)
    REFERENCES constructors (constructor_id)
    ON UPDATE CASCADE
);

CREATE UNIQUE INDEX id_laptop_UNIQUE ON laptops(laptop_id);
CREATE INDEX fk_laptop_shop ON laptops(id_shop);
CREATE INDEX fk_laptop_constructors ON laptops(id_constructors);