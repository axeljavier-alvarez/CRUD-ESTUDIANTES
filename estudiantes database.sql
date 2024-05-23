/* drop database db_estudiantes; */


/* drop database db_estudiantes; */


create database db_estudiantes;
use db_estudiantes;

select * from db_estudiantes.tipos_sangre;
CREATE TABLE `tipos_sangre` (
  `id_tipo_sangre` smallint NOT NULL AUTO_INCREMENT,
  `tipo_sangre` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id_tipo_sangre`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `estudiantes` (
  `id_estudiante` smallint NOT NULL AUTO_INCREMENT,
  `codigo` varchar(10) DEFAULT NULL,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `direccion` varchar(100) DEFAULT NULL,
  `telefono` int DEFAULT NULL,
  `fecha_nacimiento` date DEFAULT NULL,

  PRIMARY KEY (`id_estudiante`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


ALTER TABLE `db_estudiantes`.`estudiantes` 
ADD COLUMN `id_tipo_sangre` SMALLINT NULL AFTER `fecha_nacimiento`,
ADD INDEX `id_tipo_sangre_idx` (`id_tipo_sangre` ASC) VISIBLE;
;
ALTER TABLE `db_estudiantes`.`estudiantes` 
ADD CONSTRAINT `id_tipo_sangre_tipos_sangre_estudiantes`
  FOREIGN KEY (`id_tipo_sangre`)
  REFERENCES `db_estudiantes`.`tipos_sangre` (`id_tipo_sangre`)
  ON DELETE RESTRICT
  ON UPDATE CASCADE;