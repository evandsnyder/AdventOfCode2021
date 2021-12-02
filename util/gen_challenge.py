# This script generates generic, empty files for all challenges

from pathlib import Path
from string import Template


def main():
    days = {
        1: "One",
        2: "Two",
        3: "Three",
        4: "Four",
        5: "Five",
        6: "Six",
        7: "Seven",
        8: "Eight",
        9: "Nine",
        10: "Ten",
        11: "Eleven",
        12: "Twelve",
        13: "Thirteen",
        14: "Fourteen",
        15: "Fifteen",
        16: "Sixteen",
        17: "Seventeen",
        18: "Eighteen",
        19: "Nineteen",
        20: "Twenty",
        21: "TwentyOne",
        22: "TwentyTwo",
        23: "TwentyThree",
        24: "TwentyFour",
        25: "TwentyFive",
        26: "TwentySix",
        27: "TwentySeven",
        28: "TwentyEight",
        29: "TwentyNine",
        30: "Thirty",
        31: "ThirtyOne"
    }
    
    with open("resources/templates/header.txt") as f:
        header_template = Template(f.read())
    with open("resources/templates/source.txt") as f:
        source_template = Template(f.read())
    
    header_path = Path("include")
    source_path = Path("src")
    
    for k,v in days.items():
        header_file = Path(header_path / f"Day{v}Solver.hpp")
        if not header_file.exists():
            with open(header_file, 'w') as f:
                f.write(header_template.safe_substitute({"DAY": v}))
        source_file = Path(source_path / f"Day{v}Solver.cpp")
        if not source_file.exists():
            with open(source_file, 'w') as f:
                f.write(source_template.safe_substitute({"DAY": v}))
        
        # Create the case statements... ?
        print(f"case {k}: return new Day{v}Solver(\"../resources/day_{v.lower()}_input.txt\");")



if __name__ == "__main__":
    main()
