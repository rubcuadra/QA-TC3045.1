require 'rubygems'
require 'selenium-webdriver'
#require 'watir'
#browser = Watir::Browser.new :firefox
#browser.close

browser = Selenium::WebDriver.for :safari
browser.manage.window.maximize
wait = Selenium::WebDriver::Wait.new(:timeout => 10)
browser.get "https://docs.google.com/forms/d/e/1FAIpQLScibDlJbtkFcjSXUBLmfupPkqKslmHIpjHGHdNberFVSNP6Pw/viewform?c=0&w=1"

browser.find_element(:name, "entry.565481634").send_keys "Ruben Cuadra Espindola"
browser.find_element(:name, "entry.1599836428").send_keys "A01019102"

#Validations
checkboxes = browser.execute_script( %& return document.querySelectorAll('[role="checkbox"]'); & )
raise "No hay 6 Checkboxes en 'Black box testing are applicable for'" unless checkboxes.size == 6
checkboxes[3].click
checkboxes[4].click
checkboxes[5].click

ele = browser.find_element(:xpath,".//*[@id='mG61Hd']/div/div[2]/div[2]/div[4]")
checks_dev_test_cov = ele.find_elements(:css ,".quantumWizTogglePaperradioOffRadio") 
raise 'No hay 4 Radio Buttons en "test coverage is useful for finding..."' unless checks_dev_test_cov.size == 4
checks_dev_test_cov[3].click

browser.find_element(:name, 'entry.1943388466').send_keys "Load testing is the process of putting demand on a software system or computing device and measuring its response. Load testing is performed to determine a system's behavior under both normal and anticipated peak load conditions. It helps to identify the maximum operating capacity of an application as well as any bottlenecks and determine which element is causing degradatio"

#How do you determine the test coverage of a program? 4. Executed lines / Instrumented lines
browser.find_element(:xpath,".//*[@id='mG61Hd']/div/div[2]/div[2]/div[4]/div[2]/div/content/div/label[4]/div/div[1]").click
#In Unit testing, is it difficult to set up realistic and useful tests? YES
browser.find_element(:xpath,".//*[@id='mG61Hd']/div/div[2]/div[2]/div[8]/div[2]/div/content/div/label[1]/div/div[1]").click
#Test coverage can be used to create test cases? YES
browser.find_element(:xpath,".//*[@id='mG61Hd']/div/div[2]/div[2]/div[6]/div[2]/div/content/div/label[1]/div/div[1]/div[3]/div").click
#Test coverage is useful for finding not exercised areas in a program  S.Agree
browser.find_element(:xpath,".//*[@id='mG61Hd']/div/div[2]/div[2]/div[7]/div[2]/div/content/div/label[4]/div/div[1]").click

table = browser.find_element(:css,".freebirdFormviewerViewItemsGridPinnedHeader")
rows_table = table.find_elements(:css ,".freebirdFormviewerViewItemsGridRow") 
cols_table = rows_table[0].find_elements(:css,".freebirdFormviewerViewItemsGridCell")
raise 'No hay 10 cols' unless cols_table.size-1 == 10
raise 'No hay 10 rows' unless rows_table.size-1 == 10

#Table
t_cells = browser.find_elements(css: "label.freebirdFormviewerViewItemsGridCell")
t_cells[2].click
t_cells[16].click
t_cells[25].click
t_cells[34].click
t_cells[40].click
t_cells[50].click
t_cells[65].click
t_cells[71].click
t_cells[86].click
t_cells[94].click

browser.find_element(:name, 'entry.2061122182').send_keys "Is a measure used to describe the degree to which the source code of a program is executed when a particular test suite runs"
browser.find_element(:name, 'entry.980720621').send_keys "All the possible combinations of outcomes of conditions in a decision (therefore the complete decision table) are tested at least once. Since there are only two possible outcomes of a condition (TRUE or FALSE), 2 is the basis for the number of test situations that can be created"
browser.find_element(:name, 'entry.1285916526').send_keys "Is a form of deliberately intense or thorough testing used to determine the stability of a given system or entity. It involves testing beyond normal operational capacity, often to a breaking point, in order to observe the results"

#browser.find_element(:css, '.quantumWizMenuPaperselectDropDown.exportDropDown').click
#ops = browser.execute_script( %&  return document.querySelectorAll('[role="option"]'); & )
#ops[3].click  #Soak Test

submit = browser.execute_script( %& return document.querySelectorAll('[role="button"]')[0]; & )
submit.click
sleep 2

browser.quit
