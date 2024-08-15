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
    hostile: bool
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
        v = v.upper()
        if v not in cls.CLASSES:
            raise ValueError(
                f"Invalid class '{v}'. Valid classes are: {list(cls.CLASSES.keys())}."
            )
        return v

    @validator("length")
    def validate_length(cls, v, values):
        class_ = values.get("class_")
        if class_:
            class_constraints = cls.CLASSES.get(class_)
            min_length, max_length = class_constraints["length"]
            if not (min_length <= v <= max_length):
                raise ValueError(
                    f"Invalid length for {class_}. Expected between {min_length} and {max_length}."
                )
        return v

    @validator("crew_size")
    def validate_crew_size(cls, v, values):
        class_ = values.get("class_")
        if class_:
            class_constraints = cls.CLASSES.get(class_)
            min_crew, max_crew = class_constraints["crew"]
            if not (min_crew <= v <= max_crew):
                raise ValueError(
                    f"Invalid crew size for {class_}. Expected between {min_crew} and {max_crew}."
                )
        return v

    @validator("armed")
    def validate_armed(cls, v, values):
        class_ = values.get("class_")
        if class_:
            class_constraints = cls.CLASSES.get(class_)
            if class_constraints["armed"] is False and v:
                raise ValueError(f"{class_} cannot be armed.")
        return v

    @validator("hostile")
    def validate_hostile(cls, v, values):
        class_ = values.get("class_")
        if class_:
            class_constraints = cls.CLASSES.get(class_)
            if class_constraints["hostile"] is False and v:
                raise ValueError(f"{class_} cannot be hostile.")
        return v

    @validator("name")
    def validate_name(cls, v, values):
        alignment = values.get("alignment")
        if v == "Unknown" and alignment != "ENEMY":
            raise ValueError("Name can be 'Unknown' only for ENEMY ships.")
        return v

    @validator("officers")
    def validate_officers(cls, v, values):
        crew_size = values.get("crew_size")
        if crew_size is None:
            raise ValueError("Crew size must be provided to validate officers.")
        if len(v) > crew_size:
            raise ValueError(
                f"Number of officers {len(v)} cannot exceed crew size {crew_size}."
            )
        return v
