import pdfplumber
import pandas as pd
from datetime import datetime
import os

# === Step 1: File Paths ===
pdf_path = r"C:\Users\iguru\OneDrive\ドキュメント\Sybau\Raw Data\DD_report_full.pdf"

# Generate timestamped Excel file name
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
excel_path = fr"C:\Users\iguru\OneDrive\ドキュメント\Sybau\Raw Data\marine_fisheries_data_{timestamp}.xlsx"

# Excel writer to save multiple sheets
writer = pd.ExcelWriter(excel_path, engine='openpyxl')

# === Step 2: Extract and Save Tables ===
print(f"📄 Opening PDF: {pdf_path}")
with pdfplumber.open(pdf_path) as pdf:
    table_count = 0
    for page_num, page in enumerate(pdf.pages, start=1):
        print(f"\n🔍 Processing page {page_num}...")
        tables = page.extract_tables()
        if not tables:
            print("  ⚠️ No tables found on this page.")
            continue

        for idx, table in enumerate(tables):
            if not table or len(table) < 2:
                print(f"  ⏩ Skipping empty or short table {idx + 1}")
                continue

            df = pd.DataFrame(table[1:], columns=table[0])
            df.dropna(how="all", inplace=True)

            # Limit sheet name to 31 characters
            sheet_name = f"Table_{table_count+1}_Pg{page_num}"[:31]
            df.to_excel(writer, sheet_name=sheet_name, index=False)

            print(f"  ✅ Table {idx + 1} saved to sheet: '{sheet_name}'")
            table_count += 1

# === Step 3: Finalize Excel File ===
writer.close()
print(f"\n✅ Extraction complete! {table_count} tables saved to:\n{excel_path}")
