package 正则表达式;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author robbie
 * @date Created in 2024/07/31
 */

public class test {
    public static void main(String[] args) {
        String str = "CREATE SCHEMA store;\n" +
                "CREATE SCHEMA online_sales;\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.customer_dimension\n" +
                "(\n" +
                "    customer_key int NOT NULL,\n" +
                "    customer_type varchar(16),\n" +
                "    customer_name varchar(256),\n" +
                "    customer_gender varchar(8),\n" +
                "    title varchar(8),\n" +
                "    household_id int,\n" +
                "    customer_address varchar(256),\n" +
                "    customer_city varchar(64),\n" +
                "    customer_state char(2),\n" +
                "    customer_region varchar(64),\n" +
                "    marital_status varchar(32),\n" +
                "    customer_age int,\n" +
                "    number_of_children int,\n" +
                "    annual_income int,\n" +
                "    occupation varchar(64),\n" +
                "    largest_bill_amount int,\n" +
                "    store_membership_card int,\n" +
                "    customer_since date,\n" +
                "    deal_stage varchar(32),\n" +
                "    deal_size int,\n" +
                "    last_deal_update date,\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (customer_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.product_dimension\n" +
                "(\n" +
                "    product_key int NOT NULL,\n" +
                "    product_version int NOT NULL,\n" +
                "    product_description varchar(128),\n" +
                "    sku_number char(32),\n" +
                "    category_description char(32),\n" +
                "    department_description char(32),\n" +
                "    package_type_description char(32),\n" +
                "    package_size char(32),\n" +
                "    fat_content int,\n" +
                "    diet_type char(32),\n" +
                "    weight int,\n" +
                "    weight_units_of_measure char(32),\n" +
                "    shelf_width int,\n" +
                "    shelf_height int,\n" +
                "    shelf_depth int,\n" +
                "    product_price int,\n" +
                "    product_cost int,\n" +
                "    lowest_competitor_price int,\n" +
                "    highest_competitor_price int,\n" +
                "    average_competitor_price int,\n" +
                "    discontinued_flag int,\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (product_key, product_version) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.promotion_dimension\n" +
                "(\n" +
                "    promotion_key int NOT NULL,\n" +
                "    promotion_name varchar(128),\n" +
                "    price_reduction_type varchar(32),\n" +
                "    promotion_media_type varchar(32),\n" +
                "    ad_type varchar(32),\n" +
                "    display_type varchar(32),\n" +
                "    coupon_type varchar(32),\n" +
                "    ad_media_name varchar(32),\n" +
                "    display_provider varchar(128),\n" +
                "    promotion_cost int,\n" +
                "    promotion_begin_date date,\n" +
                "    promotion_end_date date,\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (promotion_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.date_dimension\n" +
                "(\n" +
                "    date_key int NOT NULL,\n" +
                "    date date,\n" +
                "    full_date_description varchar(18),\n" +
                "    day_of_week varchar(9),\n" +
                "    day_number_in_calendar_month int,\n" +
                "    day_number_in_calendar_year int,\n" +
                "    day_number_in_fiscal_month int,\n" +
                "    day_number_in_fiscal_year int,\n" +
                "    last_day_in_week_indicator int,\n" +
                "    last_day_in_month_indicator int,\n" +
                "    calendar_week_number_in_year int,\n" +
                "    calendar_month_name varchar(9),\n" +
                "    calendar_month_number_in_year int,\n" +
                "    calendar_year_month char(7),\n" +
                "    calendar_quarter int,\n" +
                "    calendar_year_quarter char(7),\n" +
                "    calendar_half_year int,\n" +
                "    calendar_year int,\n" +
                "    holiday_indicator varchar(10),\n" +
                "    weekday_indicator char(7),\n" +
                "    selling_season varchar(32),\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (date_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.vendor_dimension\n" +
                "(\n" +
                "    vendor_key int NOT NULL,\n" +
                "    vendor_name varchar(64),\n" +
                "    vendor_address varchar(64),\n" +
                "    vendor_city varchar(64),\n" +
                "    vendor_state char(2),\n" +
                "    vendor_region varchar(32),\n" +
                "    deal_size int,\n" +
                "    last_deal_update date,\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (vendor_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.employee_dimension\n" +
                "(\n" +
                "    employee_key int NOT NULL,\n" +
                "    employee_gender varchar(8),\n" +
                "    courtesy_title varchar(8),\n" +
                "    employee_first_name varchar(64),\n" +
                "    employee_middle_initial varchar(8),\n" +
                "    employee_last_name varchar(64),\n" +
                "    employee_age int,\n" +
                "    hire_date date,\n" +
                "    employee_street_address varchar(256),\n" +
                "    employee_city varchar(64),\n" +
                "    employee_state char(2),\n" +
                "    employee_region char(32),\n" +
                "    job_title varchar(64),\n" +
                "    reports_to int,\n" +
                "    salaried_flag int,\n" +
                "    annual_salary int,\n" +
                "    hourly_rate float,\n" +
                "    vacation_days int,\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (employee_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.shipping_dimension\n" +
                "(\n" +
                "    shipping_key int NOT NULL,\n" +
                "    ship_type char(30),\n" +
                "    ship_mode char(10),\n" +
                "    ship_carrier char(20),\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (shipping_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.warehouse_dimension\n" +
                "(\n" +
                "    warehouse_key int NOT NULL,\n" +
                "    warehouse_name varchar(20),\n" +
                "    warehouse_address varchar(256),\n" +
                "    warehouse_city varchar(60),\n" +
                "    warehouse_state char(2),\n" +
                "    warehouse_region varchar(32),\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (warehouse_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.inventory_fact\n" +
                "(\n" +
                "    date_key int NOT NULL,\n" +
                "    product_key int NOT NULL,\n" +
                "    product_version int NOT NULL,\n" +
                "    warehouse_key int NOT NULL,\n" +
                "    qty_in_stock int,\n" +
                "    inventory_date date\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE store.store_dimension\n" +
                "(\n" +
                "    store_key int NOT NULL,\n" +
                "    store_name varchar(64),\n" +
                "    store_number int,\n" +
                "    store_address varchar(256),\n" +
                "    store_city varchar(64),\n" +
                "    store_state char(2),\n" +
                "    store_region varchar(64),\n" +
                "    floor_plan_type varchar(32),\n" +
                "    photo_processing_type varchar(32),\n" +
                "    financial_service_type varchar(32),\n" +
                "    selling_square_footage int,\n" +
                "    total_square_footage int,\n" +
                "    first_open_date date,\n" +
                "    last_remodel_date date,\n" +
                "    number_of_employees int,\n" +
                "    annual_shrinkage int,\n" +
                "    foot_traffic int,\n" +
                "    monthly_rent_cost int,\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (store_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE store.store_sales_fact\n" +
                "(\n" +
                "    date_key int NOT NULL,\n" +
                "    product_key int NOT NULL,\n" +
                "    product_version int NOT NULL,\n" +
                "    store_key int NOT NULL,\n" +
                "    promotion_key int NOT NULL,\n" +
                "    customer_key int NOT NULL,\n" +
                "    employee_key int NOT NULL,\n" +
                "    pos_transaction_number int NOT NULL,\n" +
                "    sales_quantity int,\n" +
                "    sales_dollar_amount int,\n" +
                "    cost_dollar_amount int,\n" +
                "    gross_profit_dollar_amount int,\n" +
                "    transaction_type varchar(16),\n" +
                "    transaction_time time,\n" +
                "    tender_type varchar(8),\n" +
                "    store_sales_date date,\n" +
                "    store_sales_datetime timestamp\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE store.store_orders_fact\n" +
                "(\n" +
                "    product_key int NOT NULL,\n" +
                "    product_version int NOT NULL,\n" +
                "    store_key int NOT NULL,\n" +
                "    vendor_key int NOT NULL,\n" +
                "    employee_key int NOT NULL,\n" +
                "    order_number int NOT NULL,\n" +
                "    date_ordered date,\n" +
                "    date_shipped date,\n" +
                "    expected_delivery_date date,\n" +
                "    date_delivered date,\n" +
                "    quantity_ordered int,\n" +
                "    quantity_delivered int,\n" +
                "    shipper_name varchar(32),\n" +
                "    unit_price int,\n" +
                "    shipping_cost int,\n" +
                "    total_order_cost int,\n" +
                "    quantity_in_stock int,\n" +
                "    reorder_level int,\n" +
                "    overstock_ceiling int\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE online_sales.online_page_dimension\n" +
                "(\n" +
                "    online_page_key int NOT NULL,\n" +
                "    start_date date,\n" +
                "    end_date date,\n" +
                "    page_number int,\n" +
                "    page_description varchar(100),\n" +
                "    page_type varchar(100),\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (online_page_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE online_sales.call_center_dimension\n" +
                "(\n" +
                "    call_center_key int NOT NULL,\n" +
                "    cc_closed_date date,\n" +
                "    cc_open_date date,\n" +
                "    cc_name varchar(50),\n" +
                "    cc_class varchar(50),\n" +
                "    cc_employees int,\n" +
                "    cc_hours char(20),\n" +
                "    cc_manager varchar(40),\n" +
                "    cc_address varchar(256),\n" +
                "    cc_city varchar(64),\n" +
                "    cc_state char(2),\n" +
                "    cc_region varchar(64),\n" +
                "    CONSTRAINT C_PRIMARY PRIMARY KEY (call_center_key) DISABLED\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE online_sales.online_sales_fact\n" +
                "(\n" +
                "    sale_date_key int NOT NULL,\n" +
                "    ship_date_key int NOT NULL,\n" +
                "    product_key int NOT NULL,\n" +
                "    product_version int NOT NULL,\n" +
                "    customer_key int NOT NULL,\n" +
                "    call_center_key int NOT NULL,\n" +
                "    online_page_key int NOT NULL,\n" +
                "    shipping_key int NOT NULL,\n" +
                "    warehouse_key int NOT NULL,\n" +
                "    promotion_key int NOT NULL,\n" +
                "    pos_transaction_number int NOT NULL,\n" +
                "    sales_quantity int,\n" +
                "    sales_dollar_amount float,\n" +
                "    ship_dollar_amount float,\n" +
                "    net_dollar_amount float,\n" +
                "    cost_dollar_amount float,\n" +
                "    gross_profit_dollar_amount float,\n" +
                "    transaction_type varchar(16),\n" +
                "    online_sales_saledate date,\n" +
                "    online_sales_shipdate date\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.vmart_load_success\n" +
                "(\n" +
                "    a int\n" +
                ");\n" +
                "\n" +
                "\n" +
                "CREATE TABLE public.vertica_test\n" +
                "(\n" +
                "    ID int,\n" +
                "    name varchar(25)\n" +
                ");\n" +
                "\n" +
                "\n" +
                "ALTER TABLE public.inventory_fact ADD CONSTRAINT fk_inventory_date FOREIGN KEY (date_key) references public.date_dimension (date_key);\n" +
                "ALTER TABLE public.inventory_fact ADD CONSTRAINT fk_inventory_product FOREIGN KEY (product_key, product_version) references public.product_dimension (product_key, product_version);\n" +
                "ALTER TABLE public.inventory_fact ADD CONSTRAINT fk_inventory_warehouse FOREIGN KEY (warehouse_key) references public.warehouse_dimension (warehouse_key);\n" +
                "ALTER TABLE store.store_sales_fact ADD CONSTRAINT fk_store_sales_date FOREIGN KEY (date_key) references public.date_dimension (date_key);\n" +
                "ALTER TABLE store.store_sales_fact ADD CONSTRAINT fk_store_sales_product FOREIGN KEY (product_key, product_version) references public.product_dimension (product_key, product_version);\n" +
                "ALTER TABLE store.store_sales_fact ADD CONSTRAINT fk_store_sales_store FOREIGN KEY (store_key) references store.store_dimension (store_key);\n" +
                "ALTER TABLE store.store_sales_fact ADD CONSTRAINT fk_store_sales_promotion FOREIGN KEY (promotion_key) references public.promotion_dimension (promotion_key);\n" +
                "ALTER TABLE store.store_sales_fact ADD CONSTRAINT fk_store_sales_customer FOREIGN KEY (customer_key) references public.customer_dimension (customer_key);\n" +
                "ALTER TABLE store.store_sales_fact ADD CONSTRAINT fk_store_sales_employee FOREIGN KEY (employee_key) references public.employee_dimension (employee_key);\n" +
                "ALTER TABLE store.store_orders_fact ADD CONSTRAINT fk_store_orders_product FOREIGN KEY (product_key, product_version) references public.product_dimension (product_key, product_version);\n" +
                "ALTER TABLE store.store_orders_fact ADD CONSTRAINT fk_store_orders_store FOREIGN KEY (store_key) references store.store_dimension (store_key);\n" +
                "ALTER TABLE store.store_orders_fact ADD CONSTRAINT fk_store_orders_vendor FOREIGN KEY (vendor_key) references public.vendor_dimension (vendor_key);\n" +
                "ALTER TABLE store.store_orders_fact ADD CONSTRAINT fk_store_orders_employee FOREIGN KEY (employee_key) references public.employee_dimension (employee_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_saledate FOREIGN KEY (sale_date_key) references public.date_dimension (date_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_shipdate FOREIGN KEY (ship_date_key) references public.date_dimension (date_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_product FOREIGN KEY (product_key, product_version) references public.product_dimension (product_key, product_version);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_customer FOREIGN KEY (customer_key) references public.customer_dimension (customer_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_cc FOREIGN KEY (call_center_key) references online_sales.call_center_dimension (call_center_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_op FOREIGN KEY (online_page_key) references online_sales.online_page_dimension (online_page_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_shipping FOREIGN KEY (shipping_key) references public.shipping_dimension (shipping_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_warehouse FOREIGN KEY (warehouse_key) references public.warehouse_dimension (warehouse_key);\n" +
                "ALTER TABLE online_sales.online_sales_fact ADD CONSTRAINT fk_online_sales_promotion FOREIGN KEY (promotion_key) references public.promotion_dimension (promotion_key);\n" +
                "\n" +
                "ALTER TABLE public.inventory_fact ALTER COLUMN inventory_date SET DEFAULT ( SELECT date_dimension.date\n" +
                " FROM public.date_dimension\n" +
                " WHERE (inventory_fact.date_key = date_dimension.date_key));\n" +
                "ALTER TABLE store.store_sales_fact ALTER COLUMN store_sales_date SET DEFAULT ( SELECT date_dimension.date\n" +
                " FROM public.date_dimension\n" +
                " WHERE (store_sales_fact.date_key = date_dimension.date_key));\n" +
                "ALTER TABLE online_sales.online_sales_fact ALTER COLUMN online_sales_saledate SET DEFAULT ( SELECT date_dimension.date\n" +
                " FROM public.date_dimension\n" +
                " WHERE (online_sales_fact.sale_date_key = date_dimension.date_key));\n" +
                "ALTER TABLE online_sales.online_sales_fact ALTER COLUMN online_sales_shipdate SET DEFAULT ( SELECT date_dimension.date\n" +
                " FROM public.date_dimension\n" +
                " WHERE (online_sales_fact.ship_date_key = date_dimension.date_key));\n" +
                "\n" +
                "CREATE PROJECTION public.date_dimension_super /*+basename(date_dimension),createtype(L)*/ \n" +
                "(\n" +
                " date_key,\n" +
                " date,\n" +
                " full_date_description,\n" +
                " day_of_week,\n" +
                " day_number_in_calendar_month,\n" +
                " day_number_in_calendar_year,\n" +
                " day_number_in_fiscal_month,\n" +
                " day_number_in_fiscal_year,\n" +
                " last_day_in_week_indicator,\n" +
                " last_day_in_month_indicator,\n" +
                " calendar_week_number_in_year,\n" +
                " calendar_month_name,\n" +
                " calendar_month_number_in_year,\n" +
                " calendar_year_month,\n" +
                " calendar_quarter,\n" +
                " calendar_year_quarter,\n" +
                " calendar_half_year,\n" +
                " calendar_year,\n" +
                " holiday_indicator,\n" +
                " weekday_indicator,\n" +
                " selling_season\n" +
                ")\n" +
                "AS\n" +
                " SELECT date_dimension.date_key,\n" +
                "        date_dimension.date,\n" +
                "        date_dimension.full_date_description,\n" +
                "        date_dimension.day_of_week,\n" +
                "        date_dimension.day_number_in_calendar_month,\n" +
                "        date_dimension.day_number_in_calendar_year,\n" +
                "        date_dimension.day_number_in_fiscal_month,\n" +
                "        date_dimension.day_number_in_fiscal_year,\n" +
                "        date_dimension.last_day_in_week_indicator,\n" +
                "        date_dimension.last_day_in_month_indicator,\n" +
                "        date_dimension.calendar_week_number_in_year,\n" +
                "        date_dimension.calendar_month_name,\n" +
                "        date_dimension.calendar_month_number_in_year,\n" +
                "        date_dimension.calendar_year_month,\n" +
                "        date_dimension.calendar_quarter,\n" +
                "        date_dimension.calendar_year_quarter,\n" +
                "        date_dimension.calendar_half_year,\n" +
                "        date_dimension.calendar_year,\n" +
                "        date_dimension.holiday_indicator,\n" +
                "        date_dimension.weekday_indicator,\n" +
                "        date_dimension.selling_season\n" +
                " FROM public.date_dimension\n" +
                " ORDER BY date_dimension.date_key\n" +
                "SEGMENTED BY hash(date_dimension.date_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.product_dimension_super /*+basename(product_dimension),createtype(L)*/ \n" +
                "(\n" +
                " product_key,\n" +
                " product_version,\n" +
                " product_description,\n" +
                " sku_number,\n" +
                " category_description,\n" +
                " department_description,\n" +
                " package_type_description,\n" +
                " package_size,\n" +
                " fat_content,\n" +
                " diet_type,\n" +
                " weight,\n" +
                " weight_units_of_measure,\n" +
                " shelf_width,\n" +
                " shelf_height,\n" +
                " shelf_depth,\n" +
                " product_price,\n" +
                " product_cost,\n" +
                " lowest_competitor_price,\n" +
                " highest_competitor_price,\n" +
                " average_competitor_price,\n" +
                " discontinued_flag\n" +
                ")\n" +
                "AS\n" +
                " SELECT product_dimension.product_key,\n" +
                "        product_dimension.product_version,\n" +
                "        product_dimension.product_description,\n" +
                "        product_dimension.sku_number,\n" +
                "        product_dimension.category_description,\n" +
                "        product_dimension.department_description,\n" +
                "        product_dimension.package_type_description,\n" +
                "        product_dimension.package_size,\n" +
                "        product_dimension.fat_content,\n" +
                "        product_dimension.diet_type,\n" +
                "        product_dimension.weight,\n" +
                "        product_dimension.weight_units_of_measure,\n" +
                "        product_dimension.shelf_width,\n" +
                "        product_dimension.shelf_height,\n" +
                "        product_dimension.shelf_depth,\n" +
                "        product_dimension.product_price,\n" +
                "        product_dimension.product_cost,\n" +
                "        product_dimension.lowest_competitor_price,\n" +
                "        product_dimension.highest_competitor_price,\n" +
                "        product_dimension.average_competitor_price,\n" +
                "        product_dimension.discontinued_flag\n" +
                " FROM public.product_dimension\n" +
                " ORDER BY product_dimension.product_key,\n" +
                "          product_dimension.product_version\n" +
                "SEGMENTED BY hash(product_dimension.product_key, product_dimension.product_version) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION store.store_dimension_super /*+basename(store_dimension),createtype(L)*/ \n" +
                "(\n" +
                " store_key,\n" +
                " store_name,\n" +
                " store_number,\n" +
                " store_address,\n" +
                " store_city,\n" +
                " store_state,\n" +
                " store_region,\n" +
                " floor_plan_type,\n" +
                " photo_processing_type,\n" +
                " financial_service_type,\n" +
                " selling_square_footage,\n" +
                " total_square_footage,\n" +
                " first_open_date,\n" +
                " last_remodel_date,\n" +
                " number_of_employees,\n" +
                " annual_shrinkage,\n" +
                " foot_traffic,\n" +
                " monthly_rent_cost\n" +
                ")\n" +
                "AS\n" +
                " SELECT store_dimension.store_key,\n" +
                "        store_dimension.store_name,\n" +
                "        store_dimension.store_number,\n" +
                "        store_dimension.store_address,\n" +
                "        store_dimension.store_city,\n" +
                "        store_dimension.store_state,\n" +
                "        store_dimension.store_region,\n" +
                "        store_dimension.floor_plan_type,\n" +
                "        store_dimension.photo_processing_type,\n" +
                "        store_dimension.financial_service_type,\n" +
                "        store_dimension.selling_square_footage,\n" +
                "        store_dimension.total_square_footage,\n" +
                "        store_dimension.first_open_date,\n" +
                "        store_dimension.last_remodel_date,\n" +
                "        store_dimension.number_of_employees,\n" +
                "        store_dimension.annual_shrinkage,\n" +
                "        store_dimension.foot_traffic,\n" +
                "        store_dimension.monthly_rent_cost\n" +
                " FROM store.store_dimension\n" +
                " ORDER BY store_dimension.store_key\n" +
                "SEGMENTED BY hash(store_dimension.store_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.promotion_dimension_super /*+basename(promotion_dimension),createtype(L)*/ \n" +
                "(\n" +
                " promotion_key,\n" +
                " promotion_name,\n" +
                " price_reduction_type,\n" +
                " promotion_media_type,\n" +
                " ad_type,\n" +
                " display_type,\n" +
                " coupon_type,\n" +
                " ad_media_name,\n" +
                " display_provider,\n" +
                " promotion_cost,\n" +
                " promotion_begin_date,\n" +
                " promotion_end_date\n" +
                ")\n" +
                "AS\n" +
                " SELECT promotion_dimension.promotion_key,\n" +
                "        promotion_dimension.promotion_name,\n" +
                "        promotion_dimension.price_reduction_type,\n" +
                "        promotion_dimension.promotion_media_type,\n" +
                "        promotion_dimension.ad_type,\n" +
                "        promotion_dimension.display_type,\n" +
                "        promotion_dimension.coupon_type,\n" +
                "        promotion_dimension.ad_media_name,\n" +
                "        promotion_dimension.display_provider,\n" +
                "        promotion_dimension.promotion_cost,\n" +
                "        promotion_dimension.promotion_begin_date,\n" +
                "        promotion_dimension.promotion_end_date\n" +
                " FROM public.promotion_dimension\n" +
                " ORDER BY promotion_dimension.promotion_key\n" +
                "SEGMENTED BY hash(promotion_dimension.promotion_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.vendor_dimension_super /*+basename(vendor_dimension),createtype(L)*/ \n" +
                "(\n" +
                " vendor_key,\n" +
                " vendor_name,\n" +
                " vendor_address,\n" +
                " vendor_city,\n" +
                " vendor_state,\n" +
                " vendor_region,\n" +
                " deal_size,\n" +
                " last_deal_update\n" +
                ")\n" +
                "AS\n" +
                " SELECT vendor_dimension.vendor_key,\n" +
                "        vendor_dimension.vendor_name,\n" +
                "        vendor_dimension.vendor_address,\n" +
                "        vendor_dimension.vendor_city,\n" +
                "        vendor_dimension.vendor_state,\n" +
                "        vendor_dimension.vendor_region,\n" +
                "        vendor_dimension.deal_size,\n" +
                "        vendor_dimension.last_deal_update\n" +
                " FROM public.vendor_dimension\n" +
                " ORDER BY vendor_dimension.vendor_key\n" +
                "SEGMENTED BY hash(vendor_dimension.vendor_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.customer_dimension_super /*+basename(customer_dimension),createtype(L)*/ \n" +
                "(\n" +
                " customer_key,\n" +
                " customer_type,\n" +
                " customer_name,\n" +
                " customer_gender,\n" +
                " title,\n" +
                " household_id,\n" +
                " customer_address,\n" +
                " customer_city,\n" +
                " customer_state,\n" +
                " customer_region,\n" +
                " marital_status,\n" +
                " customer_age,\n" +
                " number_of_children,\n" +
                " annual_income,\n" +
                " occupation,\n" +
                " largest_bill_amount,\n" +
                " store_membership_card,\n" +
                " customer_since,\n" +
                " deal_stage,\n" +
                " deal_size,\n" +
                " last_deal_update\n" +
                ")\n" +
                "AS\n" +
                " SELECT customer_dimension.customer_key,\n" +
                "        customer_dimension.customer_type,\n" +
                "        customer_dimension.customer_name,\n" +
                "        customer_dimension.customer_gender,\n" +
                "        customer_dimension.title,\n" +
                "        customer_dimension.household_id,\n" +
                "        customer_dimension.customer_address,\n" +
                "        customer_dimension.customer_city,\n" +
                "        customer_dimension.customer_state,\n" +
                "        customer_dimension.customer_region,\n" +
                "        customer_dimension.marital_status,\n" +
                "        customer_dimension.customer_age,\n" +
                "        customer_dimension.number_of_children,\n" +
                "        customer_dimension.annual_income,\n" +
                "        customer_dimension.occupation,\n" +
                "        customer_dimension.largest_bill_amount,\n" +
                "        customer_dimension.store_membership_card,\n" +
                "        customer_dimension.customer_since,\n" +
                "        customer_dimension.deal_stage,\n" +
                "        customer_dimension.deal_size,\n" +
                "        customer_dimension.last_deal_update\n" +
                " FROM public.customer_dimension\n" +
                " ORDER BY customer_dimension.customer_key\n" +
                "SEGMENTED BY hash(customer_dimension.customer_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.employee_dimension_super /*+basename(employee_dimension),createtype(L)*/ \n" +
                "(\n" +
                " employee_key,\n" +
                " employee_gender,\n" +
                " courtesy_title,\n" +
                " employee_first_name,\n" +
                " employee_middle_initial,\n" +
                " employee_last_name,\n" +
                " employee_age,\n" +
                " hire_date,\n" +
                " employee_street_address,\n" +
                " employee_city,\n" +
                " employee_state,\n" +
                " employee_region,\n" +
                " job_title,\n" +
                " reports_to,\n" +
                " salaried_flag,\n" +
                " annual_salary,\n" +
                " hourly_rate,\n" +
                " vacation_days\n" +
                ")\n" +
                "AS\n" +
                " SELECT employee_dimension.employee_key,\n" +
                "        employee_dimension.employee_gender,\n" +
                "        employee_dimension.courtesy_title,\n" +
                "        employee_dimension.employee_first_name,\n" +
                "        employee_dimension.employee_middle_initial,\n" +
                "        employee_dimension.employee_last_name,\n" +
                "        employee_dimension.employee_age,\n" +
                "        employee_dimension.hire_date,\n" +
                "        employee_dimension.employee_street_address,\n" +
                "        employee_dimension.employee_city,\n" +
                "        employee_dimension.employee_state,\n" +
                "        employee_dimension.employee_region,\n" +
                "        employee_dimension.job_title,\n" +
                "        employee_dimension.reports_to,\n" +
                "        employee_dimension.salaried_flag,\n" +
                "        employee_dimension.annual_salary,\n" +
                "        employee_dimension.hourly_rate,\n" +
                "        employee_dimension.vacation_days\n" +
                " FROM public.employee_dimension\n" +
                " ORDER BY employee_dimension.employee_key\n" +
                "SEGMENTED BY hash(employee_dimension.employee_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.warehouse_dimension_super /*+basename(warehouse_dimension),createtype(L)*/ \n" +
                "(\n" +
                " warehouse_key,\n" +
                " warehouse_name,\n" +
                " warehouse_address,\n" +
                " warehouse_city,\n" +
                " warehouse_state,\n" +
                " warehouse_region\n" +
                ")\n" +
                "AS\n" +
                " SELECT warehouse_dimension.warehouse_key,\n" +
                "        warehouse_dimension.warehouse_name,\n" +
                "        warehouse_dimension.warehouse_address,\n" +
                "        warehouse_dimension.warehouse_city,\n" +
                "        warehouse_dimension.warehouse_state,\n" +
                "        warehouse_dimension.warehouse_region\n" +
                " FROM public.warehouse_dimension\n" +
                " ORDER BY warehouse_dimension.warehouse_key\n" +
                "SEGMENTED BY hash(warehouse_dimension.warehouse_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.shipping_dimension_super /*+basename(shipping_dimension),createtype(L)*/ \n" +
                "(\n" +
                " shipping_key,\n" +
                " ship_type,\n" +
                " ship_mode,\n" +
                " ship_carrier\n" +
                ")\n" +
                "AS\n" +
                " SELECT shipping_dimension.shipping_key,\n" +
                "        shipping_dimension.ship_type,\n" +
                "        shipping_dimension.ship_mode,\n" +
                "        shipping_dimension.ship_carrier\n" +
                " FROM public.shipping_dimension\n" +
                " ORDER BY shipping_dimension.shipping_key\n" +
                "SEGMENTED BY hash(shipping_dimension.shipping_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION online_sales.online_page_dimension_super /*+basename(online_page_dimension),createtype(L)*/ \n" +
                "(\n" +
                " online_page_key,\n" +
                " start_date,\n" +
                " end_date,\n" +
                " page_number,\n" +
                " page_description,\n" +
                " page_type\n" +
                ")\n" +
                "AS\n" +
                " SELECT online_page_dimension.online_page_key,\n" +
                "        online_page_dimension.start_date,\n" +
                "        online_page_dimension.end_date,\n" +
                "        online_page_dimension.page_number,\n" +
                "        online_page_dimension.page_description,\n" +
                "        online_page_dimension.page_type\n" +
                " FROM online_sales.online_page_dimension\n" +
                " ORDER BY online_page_dimension.online_page_key\n" +
                "SEGMENTED BY hash(online_page_dimension.online_page_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION online_sales.call_center_dimension_super /*+basename(call_center_dimension),createtype(L)*/ \n" +
                "(\n" +
                " call_center_key,\n" +
                " cc_closed_date,\n" +
                " cc_open_date,\n" +
                " cc_name,\n" +
                " cc_class,\n" +
                " cc_employees,\n" +
                " cc_hours,\n" +
                " cc_manager,\n" +
                " cc_address,\n" +
                " cc_city,\n" +
                " cc_state,\n" +
                " cc_region\n" +
                ")\n" +
                "AS\n" +
                " SELECT call_center_dimension.call_center_key,\n" +
                "        call_center_dimension.cc_closed_date,\n" +
                "        call_center_dimension.cc_open_date,\n" +
                "        call_center_dimension.cc_name,\n" +
                "        call_center_dimension.cc_class,\n" +
                "        call_center_dimension.cc_employees,\n" +
                "        call_center_dimension.cc_hours,\n" +
                "        call_center_dimension.cc_manager,\n" +
                "        call_center_dimension.cc_address,\n" +
                "        call_center_dimension.cc_city,\n" +
                "        call_center_dimension.cc_state,\n" +
                "        call_center_dimension.cc_region\n" +
                " FROM online_sales.call_center_dimension\n" +
                " ORDER BY call_center_dimension.call_center_key\n" +
                "SEGMENTED BY hash(call_center_dimension.call_center_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION store.store_sales_fact_super /*+basename(store_sales_fact),createtype(L)*/ \n" +
                "(\n" +
                " date_key,\n" +
                " product_key,\n" +
                " product_version,\n" +
                " store_key,\n" +
                " promotion_key,\n" +
                " customer_key,\n" +
                " employee_key,\n" +
                " pos_transaction_number,\n" +
                " sales_quantity,\n" +
                " sales_dollar_amount,\n" +
                " cost_dollar_amount,\n" +
                " gross_profit_dollar_amount,\n" +
                " transaction_type,\n" +
                " transaction_time,\n" +
                " tender_type,\n" +
                " store_sales_date,\n" +
                " store_sales_datetime\n" +
                ")\n" +
                "AS\n" +
                " SELECT store_sales_fact.date_key,\n" +
                "        store_sales_fact.product_key,\n" +
                "        store_sales_fact.product_version,\n" +
                "        store_sales_fact.store_key,\n" +
                "        store_sales_fact.promotion_key,\n" +
                "        store_sales_fact.customer_key,\n" +
                "        store_sales_fact.employee_key,\n" +
                "        store_sales_fact.pos_transaction_number,\n" +
                "        store_sales_fact.sales_quantity,\n" +
                "        store_sales_fact.sales_dollar_amount,\n" +
                "        store_sales_fact.cost_dollar_amount,\n" +
                "        store_sales_fact.gross_profit_dollar_amount,\n" +
                "        store_sales_fact.transaction_type,\n" +
                "        store_sales_fact.transaction_time,\n" +
                "        store_sales_fact.tender_type,\n" +
                "        store_sales_fact.store_sales_date,\n" +
                "        store_sales_fact.store_sales_datetime\n" +
                " FROM store.store_sales_fact\n" +
                " ORDER BY store_sales_fact.employee_key,\n" +
                "          store_sales_fact.customer_key,\n" +
                "          store_sales_fact.promotion_key,\n" +
                "          store_sales_fact.store_key,\n" +
                "          store_sales_fact.product_key,\n" +
                "          store_sales_fact.product_version,\n" +
                "          store_sales_fact.date_key,\n" +
                "          store_sales_fact.pos_transaction_number\n" +
                "SEGMENTED BY hash(store_sales_fact.date_key, store_sales_fact.product_key, store_sales_fact.product_version, store_sales_fact.store_key, store_sales_fact.promotion_key, store_sales_fact.customer_key, store_sales_fact.employee_key, store_sales_fact.pos_transaction_number) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION store.store_orders_fact_super /*+basename(store_orders_fact),createtype(L)*/ \n" +
                "(\n" +
                " product_key,\n" +
                " product_version,\n" +
                " store_key,\n" +
                " vendor_key,\n" +
                " employee_key,\n" +
                " order_number,\n" +
                " date_ordered,\n" +
                " date_shipped,\n" +
                " expected_delivery_date,\n" +
                " date_delivered,\n" +
                " quantity_ordered,\n" +
                " quantity_delivered,\n" +
                " shipper_name,\n" +
                " unit_price,\n" +
                " shipping_cost,\n" +
                " total_order_cost,\n" +
                " quantity_in_stock,\n" +
                " reorder_level,\n" +
                " overstock_ceiling\n" +
                ")\n" +
                "AS\n" +
                " SELECT store_orders_fact.product_key,\n" +
                "        store_orders_fact.product_version,\n" +
                "        store_orders_fact.store_key,\n" +
                "        store_orders_fact.vendor_key,\n" +
                "        store_orders_fact.employee_key,\n" +
                "        store_orders_fact.order_number,\n" +
                "        store_orders_fact.date_ordered,\n" +
                "        store_orders_fact.date_shipped,\n" +
                "        store_orders_fact.expected_delivery_date,\n" +
                "        store_orders_fact.date_delivered,\n" +
                "        store_orders_fact.quantity_ordered,\n" +
                "        store_orders_fact.quantity_delivered,\n" +
                "        store_orders_fact.shipper_name,\n" +
                "        store_orders_fact.unit_price,\n" +
                "        store_orders_fact.shipping_cost,\n" +
                "        store_orders_fact.total_order_cost,\n" +
                "        store_orders_fact.quantity_in_stock,\n" +
                "        store_orders_fact.reorder_level,\n" +
                "        store_orders_fact.overstock_ceiling\n" +
                " FROM store.store_orders_fact\n" +
                " ORDER BY store_orders_fact.employee_key,\n" +
                "          store_orders_fact.vendor_key,\n" +
                "          store_orders_fact.store_key,\n" +
                "          store_orders_fact.product_key,\n" +
                "          store_orders_fact.product_version,\n" +
                "          store_orders_fact.order_number,\n" +
                "          store_orders_fact.date_ordered,\n" +
                "          store_orders_fact.date_shipped\n" +
                "SEGMENTED BY hash(store_orders_fact.product_key, store_orders_fact.product_version, store_orders_fact.store_key, store_orders_fact.vendor_key, store_orders_fact.employee_key, store_orders_fact.order_number, store_orders_fact.date_ordered, store_orders_fact.date_shipped) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION online_sales.online_sales_fact_super /*+basename(online_sales_fact),createtype(L)*/ \n" +
                "(\n" +
                " sale_date_key,\n" +
                " ship_date_key,\n" +
                " product_key,\n" +
                " product_version,\n" +
                " customer_key,\n" +
                " call_center_key,\n" +
                " online_page_key,\n" +
                " shipping_key,\n" +
                " warehouse_key,\n" +
                " promotion_key,\n" +
                " pos_transaction_number,\n" +
                " sales_quantity,\n" +
                " sales_dollar_amount,\n" +
                " ship_dollar_amount,\n" +
                " net_dollar_amount,\n" +
                " cost_dollar_amount,\n" +
                " gross_profit_dollar_amount,\n" +
                " transaction_type,\n" +
                " online_sales_saledate,\n" +
                " online_sales_shipdate\n" +
                ")\n" +
                "AS\n" +
                " SELECT online_sales_fact.sale_date_key,\n" +
                "        online_sales_fact.ship_date_key,\n" +
                "        online_sales_fact.product_key,\n" +
                "        online_sales_fact.product_version,\n" +
                "        online_sales_fact.customer_key,\n" +
                "        online_sales_fact.call_center_key,\n" +
                "        online_sales_fact.online_page_key,\n" +
                "        online_sales_fact.shipping_key,\n" +
                "        online_sales_fact.warehouse_key,\n" +
                "        online_sales_fact.promotion_key,\n" +
                "        online_sales_fact.pos_transaction_number,\n" +
                "        online_sales_fact.sales_quantity,\n" +
                "        online_sales_fact.sales_dollar_amount,\n" +
                "        online_sales_fact.ship_dollar_amount,\n" +
                "        online_sales_fact.net_dollar_amount,\n" +
                "        online_sales_fact.cost_dollar_amount,\n" +
                "        online_sales_fact.gross_profit_dollar_amount,\n" +
                "        online_sales_fact.transaction_type,\n" +
                "        online_sales_fact.online_sales_saledate,\n" +
                "        online_sales_fact.online_sales_shipdate\n" +
                " FROM online_sales.online_sales_fact\n" +
                " ORDER BY online_sales_fact.promotion_key,\n" +
                "          online_sales_fact.warehouse_key,\n" +
                "          online_sales_fact.shipping_key,\n" +
                "          online_sales_fact.online_page_key,\n" +
                "          online_sales_fact.call_center_key,\n" +
                "          online_sales_fact.customer_key,\n" +
                "          online_sales_fact.product_key,\n" +
                "          online_sales_fact.product_version\n" +
                "SEGMENTED BY hash(online_sales_fact.sale_date_key, online_sales_fact.ship_date_key, online_sales_fact.product_key, online_sales_fact.product_version, online_sales_fact.customer_key, online_sales_fact.call_center_key, online_sales_fact.online_page_key, online_sales_fact.shipping_key) ALL NODES OFFSET 0;\n" +
                "\n" +
                "CREATE PROJECTION public.inventory_fact_super /*+basename(inventory_fact),createtype(L)*/ \n" +
                "(\n" +
                " date_key,\n" +
                " product_key,\n" +
                " product_version,\n" +
                " warehouse_key,\n" +
                " qty_in_stock,\n" +
                " inventory_date\n" +
                ")\n" +
                "AS\n" +
                " SELECT inventory_fact.date_key,\n" +
                "        inventory_fact.product_key,\n" +
                "        inventory_fact.product_version,\n" +
                "        inventory_fact.warehouse_key,\n" +
                "        inventory_fact.qty_in_stock,\n" +
                "        inventory_fact.inventory_date\n" +
                " FROM public.inventory_fact\n" +
                " ORDER BY inventory_fact.warehouse_key,\n" +
                "          inventory_fact.product_key,\n" +
                "          inventory_fact.product_version,\n" +
                "          inventory_fact.date_key,\n" +
                "          inventory_fact.qty_in_stock\n" +
                "SEGMENTED BY hash(inventory_fact.date_key, inventory_fact.product_key, inventory_fact.product_version, inventory_fact.warehouse_key, inventory_fact.qty_in_stock) ALL NODES OFFSET 0;\n" +
                "\n" +
                "\n" +
                "CREATE FUNCTION public.isOrContains(map Long Varchar, val Varchar)\n" +
                "RETURN boolean AS\n" +
                "BEGIN\n" +
                "RETURN CASE WHEN (public.MapSize(map) <> (-1)) THEN public.MapContainsValue(map, val) ELSE (map = (val)) END;\n" +
                "END;\n" +
                "\n" +
                "CREATE PROCEDURE public.my_typetest1(a1 binary(1), a2 varbinary, a3 long varbinary, a4 boolean, a5 char(1), a6 varchar, a7 long varchar, a8 date, a9 time, a10 timestamp, a11 float, a12 float, a13 float, a14 float, a15 float, a16 int, a17 int, a18 int, a19 int, a20 int, a21 int)\n" +
                "LANGUAGE 'PL/vSQL'\n" +
                "SECURITY INVOKER\n" +
                "AS '\n" +
                "BEGIN\n" +
                "    RAISE NOTICE ''hello'';\n" +
                "END\n" +
                "';\n" +
                "\n" +
                "CREATE PROCEDURE public.my_insert(ID int, name varchar(25))\n" +
                "LANGUAGE 'PL/vSQL'\n" +
                "SECURITY INVOKER\n" +
                "AS '\n" +
                "BEGIN\n" +
                "\tPERFORM insert into public.vertica_test values(ID,name);\n" +
                "END\n" +
                "';\n" +
                "\n" +
                "CREATE PROCEDURE public.my_hello()\n" +
                "LANGUAGE 'PL/vSQL'\n" +
                "SECURITY INVOKER\n" +
                "AS '\n" +
                "BEGIN\n" +
                "\tRAISE NOTICE ''hello'';\n" +
                "END\n" +
                "';\n" +
                "\n" +
                "CREATE PROCEDURE public.my_long_varchar(a7 long varchar)\n" +
                "LANGUAGE 'PL/vSQL'\n" +
                "SECURITY INVOKER\n" +
                "AS '\n" +
                "BEGIN\n" +
                "\tRAISE NOTICE ''hello'';\n" +
                "END\n" +
                "';\n" +
                "\n" +
                "SELECT MARK_DESIGN_KSAFE(0);\n";
//        System.out.println(str.length());
        String longstr = "";
        for (int i = 0; i < 1; i++) {
            longstr += str;
        }
        System.out.println("repeat done");
        String typeRegex = "CREATE PROCEDURE public\\.my_insert\\(ID int, name varchar\\(25\\)\\).*?END\n" +
                "';";
        Pattern typePattern = Pattern.compile(typeRegex, Pattern.DOTALL);
        long startTime = System.currentTimeMillis();
        Matcher matcher = typePattern.matcher(longstr);
        if (matcher.find()) {
            System.out.println(matcher.group(0));
        }
        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime;
        System.out.println("Execution time: " + duration + " ms");
    }
}
