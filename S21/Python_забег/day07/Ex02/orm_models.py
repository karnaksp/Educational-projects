from sqlalchemy import Column, Integer, String, Float, Boolean, ForeignKey
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship

Base = declarative_base()


class Spaceship(Base):
    __tablename__ = "spaceships"
    id = Column(Integer, primary_key=True)
    alignment = Column(String)
    name = Column(String)
    ship_class = Column(String)
    length = Column(Float)
    crew_size = Column(Integer)
    armed = Column(Boolean)
    officers = relationship("Officer", back_populates="spaceship")


class Officer(Base):
    __tablename__ = "officers"
    id = Column(Integer, primary_key=True)
    first_name = Column(String)
    last_name = Column(String)
    rank = Column(String)
    spaceship_id = Column(Integer, ForeignKey("spaceships.id"))
    spaceship = relationship("Spaceship", back_populates="officers")
