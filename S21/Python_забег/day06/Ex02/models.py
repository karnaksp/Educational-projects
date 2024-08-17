from sqlalchemy import (
    Column,
    Integer,
    String,
    Float,
    Boolean,
    Table,
    ForeignKey,
    UniqueConstraint,
    PrimaryKeyConstraint,
)
from sqlalchemy.orm import declarative_base, relationship

Base = declarative_base()

spaceship_officers = Table(
    "spaceship_officers",
    Base.metadata,
    Column("spaceship_id", Integer, ForeignKey("spaceships.id")),
    Column("officer_id", Integer, ForeignKey("officers.id")),
    PrimaryKeyConstraint("spaceship_id", "officer_id"),
)


class OfficerORM(Base):
    __tablename__ = "officers"
    id = Column(Integer, primary_key=True)
    first_name = Column(String, nullable=False)
    last_name = Column(String, nullable=False)
    rank = Column(String, nullable=False)
    __table_args__ = (
        UniqueConstraint("first_name", "last_name", "rank", name="unique_officer"),
    )


class SpaceshipORM(Base):
    __tablename__ = "spaceships"
    id = Column(Integer, primary_key=True)
    alignment = Column(String, nullable=False)
    name = Column(String, nullable=False)
    class_ = Column("class", String, nullable=False)
    length = Column(Float, nullable=False)
    crew_size = Column(Integer, nullable=False)
    armed = Column(Boolean, nullable=False)
    hostile = Column(Boolean, nullable=False)
    speed = Column(Float, nullable=True)  # Optional
    officers = relationship(
        "OfficerORM", secondary=spaceship_officers, backref="spaceships"
    )
