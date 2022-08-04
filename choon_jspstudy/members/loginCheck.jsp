<%@page import="com.jsp.members.MembersDTO"%>
<%@page import="com.jsp.members.MembersDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%--
	넘어온 데이터 받기
	DAO 객체 생성하기
	userCheck 메소드 호출 후 결과값 받기
	결과값 받아서 아이디랑 비밀번호가 맞다면
	session 객체에 id와 name값 넣기
	session.setAtribute("id", id)
	session.setAttribute("name",name);
 --%>
 	<%
 		request.setCharacterEncoding("UTF-8");
 		String id = request.getParameter("id");
 		String pw = request.getParameter("pw");
 		
 		MembersDAO dao = MembersDAO.getInstance();
 		int result = dao.userCheck(id, pw);
 		if(result == -1){ // 회원이 없는 경우
 	%>
 		<script>
 			alert('아이디가 존재하지 않습니다.');
 			history.back();
 		</script>
 	<%		
 		}else if(result == 0){//비밀번호가 틀린 경우
 	%>
 		<script>
 			alert('비밀번호가 틀립니다.');
 			history.back();
 		</script>
 	<% 
 		}else if(result == 1){//아이디 비밀번호가 맞는 경우 (로그인 OK)
 			MembersDTO dto = dao.getMember(id);
 		if(dto == null){
 	%>
 		<script>
 			alert('존재하지 않는 회원입니다.');
 			history.back();
 		</script>
 	<%
 			}else{
 				String name = dto.getName();
 				session.setAttribute("id", id);
 				session.setAttribute("name", name);
 				response.sendRedirect("main.jsp");
 			}
 		}
 	%>
 	
</body>
</html>