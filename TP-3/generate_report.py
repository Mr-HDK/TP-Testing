import csv
import os
from robot.api import ExecutionResult, ResultVisitor

class TestReportVisitor(ResultVisitor):
    def __init__(self, csv_filename):
        self.csv_filename = csv_filename
        self.rows = []

    def visit_test(self, test):
        self.rows.append([test.name, test.status, test.message])

    def save_to_csv(self):
        with open(self.csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(["Test Case", "Status", "Message"])
            writer.writerows(self.rows)

def generate_csv_report(output_xml, csv_filename):
    result = ExecutionResult(output_xml)
    visitor = TestReportVisitor(csv_filename)
    result.visit(visitor)
    visitor.save_to_csv()

if __name__ == "_main_":
    output_file = "TP-3\output.xml"
    csv_file = "test_report.csv"
    if os.path.exists(output_file):
        generate_csv_report(output_file, csv_file)
        print(f"Rapport généré : {csv_file}")
    else:
        print(f"Le fichier {output_file} est introuvable.")