package aaa.com;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class AaaController
 */
@WebServlet({"/aaa.do","/aaaColor.do","/dongaMovieList.do","/loadUrl.do"})
public class AaaController extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AaaController() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	//	response.getWriter().append("Served at: ").append(request.getContextPath());
	
		String url = request.getServletPath();
		
		if(url.equals("/aaa.do")) {
			response.sendRedirect("aaa.jsp");
		} //else if(url.equals("/aaaColor.do")) {
		//	response.getWriter().append("[\"green\",\"yellow\"]");
		///	}
		else if(url.equals("/loadUrl.do")) {
			response.sendRedirect("loadUrl.jsp");
			//response.sendRedirect("dongaMovieList.jsp");
			}
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
