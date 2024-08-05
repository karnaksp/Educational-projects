from pydantic import BaseModel, Field, validator
from typing import List, ClassVar, Dict, Tuple
import config


class Officer(BaseModel):
    first_name: str
    last_name: str
    rank: str


class Spaceship(BaseModel):
    alignment: str
    name: str
    class_: str = Field(alias="class_")
    length: float
    crew_size: int
    armed: bool
    officers: List[Officer]

    CLASSES: ClassVar[Dict[str, Dict[str, Tuple[float, float]]]] = {
        "CORVETTE": {
            "length": (80, 250),
            "crew": (4, 10),
            "armed": True,
            "hostile": True,
        },
        "FRIGATE": {
            "length": (300, 600),
            "crew": (10, 15),
            "armed": True,
            "hostile": False,
        },
        "CRUISER": {
            "length": (500, 1000),
            "crew": (15, 30),
            "armed": True,
            "hostile": True,
        },
        "DESTROYER": {
            "length": (800, 2000),
            "crew": (50, 80),
            "armed": True,
            "hostile": False,
        },
        "CARRIER": {
            "length": (1000, 4000),
            "crew": (120, 250),
            "armed": False,
            "hostile": True,
        },
        "DREADNOUGHT": {
            "length": (5000, 20000),
            "crew": (300, 500),
            "armed": True,
            "hostile": True,
        },
    }

    @validator("class_")
    def validate_class(cls, v):
        if v not in cls.CLASSES:
            raise ValueError("Invalid class")
        return v

    @validator("length")
    def validate_length(cls, v, values):
        class_ = values.get("class_")
        class_constraints = cls.CLASSES.get(class_)
        if class_constraints and not (
            class_constraints["length"][0] <= v <= class_constraints["length"][1]
        ):
            raise ValueError(f"Invalid length for {class_}")
        return v

    @validator("crew_size")
    def validate_crew_size(cls, v, values):
        class_ = values.get("class_")
        class_constraints = cls.CLASSES.get(class_)
        if class_constraints and not (
            class_constraints["crew"][0] <= v <= class_constraints["crew"][1]
        ):
            raise ValueError(f"Invalid crew size for {class_}")
        return v

    @validator("armed")
    def validate_armed(cls, v, values):
        class_ = values.get("class_")
        class_constraints = cls.CLASSES.get(class_)
        if class_constraints and class_constraints["armed"] is False and v:
            raise ValueError(f"{class_} cannot be armed")
        return v

    @validator("name")
    def validate_name(cls, v, values):
        alignment = values.get("alignment")
        if v == "Unknown" and alignment != "ENEMY":
            raise ValueError("Name can be 'Unknown' only for ENEMY ships")
        return v
