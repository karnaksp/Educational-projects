SELECT 
student.lastname AS 'Фамилия_студента', 
  AVG(daily_mark_rating_record.exam) AS '   Сумма   '
FROM ref_subject
INNER JOIN mark_rating_sheet ON mark_rating_sheet.subject_id = ref_subject.id
INNER JOIN daily_mark_rating_record ON daily_mark_rating_record.mark_rating_sheet_id = mark_rating_sheet.id
INNER JOIN student ON daily_mark_rating_record.student_id = student.id
GROUP BY student.lastname
HAVING AVG(daily_mark_rating_record.exam)>30
ORDER BY 
         1 ASC 
		 ;