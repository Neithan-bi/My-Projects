import re
import pandas as pd
from docx import Document

# Load the DOCX file
doc = Document(r"C:\Users\iguru\OneDrive\Desktop\Code Files\Python Files\CCP\AWS_CCP_v1.1_Set1Lekhya_Corrected-Copy.docx")
lines = [p.text.strip() for p in doc.paragraphs if p.text.strip()]

# Helper variables
questions = []
q_block = []

for line in lines:
    if line.startswith("Serial No:"):
        if q_block:
            questions.append(q_block)
            q_block = []
    q_block.append(line)
if q_block:
    questions.append(q_block)

# Parse and format
formatted = []

for idx, q in enumerate(questions, 1):
    q_text = ""
    options = {}
    correct_answer = ""
    correct_exp = ""
    incorrect_exp = []
    difficulty = "Unknown"
    category = "Unknown"
    
    i = 0
    while i < len(q):
        line = q[i]
        
        if line.startswith("Question:"):
            q_text = line.replace("Question:", "").strip()
            i += 1
            while i < len(q) and not q[i].startswith("A."):
                q_text += " " + q[i].strip()
                i += 1
            continue
        
        opt_match = re.match(r"^([A-D])\. (.+)", line)
        if opt_match:
            opt = opt_match.group(1)
            opt_text = opt_match.group(2)
            i += 1
            while i < len(q) and not re.match(r"^[A-D]\. ", q[i]) and not q[i].startswith("Correct Answer:"):
                opt_text += " " + q[i]
                i += 1
            if "✅ Correct:" in opt_text:
                correct_answer = opt
                parts = opt_text.split("✅ Correct:")
                options[opt] = parts[0].strip()
                correct_exp = parts[1].strip()
            elif "❌ Incorrect:" in opt_text:
                parts = opt_text.split("❌ Incorrect:")
                options[opt] = parts[0].strip()
                incorrect_exp.append(parts[1].strip())
            else:
                options[opt] = opt_text.strip()
            continue
        
        if line.startswith("Correct Answer:"):
            correct_answer_match = re.search(r"Correct Answer: ([A-D]+)", line)
            if correct_answer_match:
                correct_answer = correct_answer_match.group(1)
        
        if line.startswith("Difficulty Level:"):
            difficulty = line.replace("Difficulty Level:", "").strip()
        
        if line.startswith("Category:"):
            category = line.replace("Category:", "").strip()
        
        i += 1

    # Format column A and B
    col_a = f"Q.No: {idx}\nDifficulty: {difficulty}\nCategory: {category}"
    col_b = f"Question: {q_text}"
    for opt in ['A', 'B', 'C', 'D']:
        if opt in options:
            col_b += f"\n{opt}) {options[opt]}"
    col_b += f"\nAnswer: {correct_answer}"
    col_b += f"\nCorrect Explanation: {correct_exp if correct_exp else 'N/A'}"
    col_b += f"\nIncorrect Explanation: {' '.join(incorrect_exp) if incorrect_exp else 'N/A'}"
    
    formatted.append([col_a, col_b])

# Create DataFrame and save
df = pd.DataFrame(formatted, columns=["Info", "Question"])
df.to_excel("AWS_Formatted_Questions.xlsx", index=False)
print("✅ Exported to AWS_Formatted_Questions.xlsx")
