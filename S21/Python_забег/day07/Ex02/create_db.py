from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from orm_models import Base

DATABASE_URL = "postgresql://user:password@localhost/spaceshipdb"

engine = create_engine(DATABASE_URL)
Base.metadata.create_all(engine)

print("Database and tables created successfully.")
